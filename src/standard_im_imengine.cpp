/** @file standard_im_imengine.cpp
 */

/*
 * Copyright (c) 2006 Qingyu Wang <qwang@redhat.com>
 * Copyright (c) 2004 James Su <suzhe@tsinghua.org.cn>
 *
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330,
 * Boston, MA  02111-1307  USA
 *
 * $Id$
 */

#define Uses_SCIM_UTILITY
#define Uses_SCIM_IMENGINE
#define Uses_SCIM_LOOKUP_TABLE
#define Uses_SCIM_CONFIG_BASE
#define Uses_SCIM_ICONV
#define Uses_STL_MAP

#ifdef HAVE_CONFIG_H
  #include <config.h>
#endif

#include <scim.h>
#include "standard_im_imengine.h"
#include "standard_im_module.h"
#include "global.h"

#define scim_module_init chinese_standard_im_LTX_scim_module_init
#define scim_module_exit chinese_standard_im_LTX_scim_module_exit
#define scim_imengine_module_init chinese_standard_im_LTX_scim_imengine_module_init
#define scim_imengine_module_create_factory chinese_standard_im_LTX_scim_imengine_module_create_factory

#define STANDARD_IM_CONFIG_PREFIX       "/StandardIM/"
#define SCIM_TRANS_CMD_HELPER_DATA  10000 + 1234

static IMM_Functions __imm_functions = {
//    "1.0.0",
    StandardIMInstance::imm_show_preedit_string,
    StandardIMInstance::imm_hide_preedit_string,
    StandardIMInstance::imm_update_preedit_string,
    StandardIMInstance::imm_update_preedit_caret,
    StandardIMInstance::imm_show_aux_string,
    StandardIMInstance::imm_hide_aux_string,
    StandardIMInstance::imm_update_aux_string,
    StandardIMInstance::imm_show_candidates_list,
    StandardIMInstance::imm_hide_candidates_list,
    StandardIMInstance::imm_update_candidates_list,
    StandardIMInstance::imm_set_focused_candidate,
    StandardIMInstance::imm_commit_string,
    StandardIMInstance::imm_register_properties,
    StandardIMInstance::imm_update_property,
    StandardIMInstance::imm_start_helper,
    StandardIMInstance::imm_stop_helper,
    StandardIMInstance::imm_send_helper_event,
    StandardIMInstance::imm_beep
//    StandardIMInstance::imm_read_config,
//    StandardIMInstance::imm_write_config
};

class StandardIMGlobal
{
    int                                  m_nr_modules;
    int                                  m_nr_ims;

    StandardIMModule                    *m_modules;

    IME_Functions                       *m_module_ime_funcs;

    std::vector <IME_InputMethod>       *m_module_ims;

    std::map <int, StandardIMInstance *> m_ics;

public:
    StandardIMGlobal ()
        : m_nr_modules (0),
          m_nr_ims (0),
          m_modules (0),
          m_module_ime_funcs (0),
          m_module_ims (0) {

        SCIM_DEBUG_IMENGINE(1) << "Construct StandardIMGlobal.\n";

        std::vector <String> mod_list;

        m_nr_modules = standard_im_get_module_list (mod_list);

        if (m_nr_modules <= 0) return;

        SCIM_DEBUG_IMENGINE(1) << "Found " << m_nr_modules << " modules.\n";

        m_modules = new StandardIMModule [m_nr_modules];
        m_module_ime_funcs = new IME_Functions [m_nr_modules];
        m_module_ims = new std::vector <IME_InputMethod> [m_nr_modules];

        for (int i = 0; i < m_nr_modules; ++i) {
            SCIM_DEBUG_IMENGINE(1) << "Loading module " << mod_list [i] << ".\n";
            if (m_modules [i].load (mod_list [i]) &&
                m_modules [i].ime_register_module (&__imm_functions, &(m_module_ime_funcs [i]))) {
                if (m_module_ime_funcs [i].initialize &&
                    m_module_ime_funcs [i].finalize &&
                    m_module_ime_funcs [i].get_number_of_input_methods &&
                    m_module_ime_funcs [i].get_input_method_info &&
                    m_module_ime_funcs [i].create_input_context &&
                    m_module_ime_funcs [i].destroy_input_context) {
                    int nr_ims;
                    m_module_ime_funcs [i].initialize ();
                    nr_ims = m_module_ime_funcs [i].get_number_of_input_methods ();
                    for (int j = 0; j < nr_ims; ++j) {
                        IME_InputMethod info;
                        if (m_module_ime_funcs [i].get_input_method_info (j, &info)) {
                            m_module_ims [i].push_back (info);
                        }
                    }
                    m_nr_ims += m_module_ims [i].size ();
                    SCIM_DEBUG_IMENGINE(1) << "Success, " << m_module_ims [i].size () << " input methods.\n";
                    continue;
                }
            }
            SCIM_DEBUG_IMENGINE(1) << "Fail.\n";
            m_modules [i].unload ();
        }
    }

    ~StandardIMGlobal () {
        SCIM_DEBUG_IMENGINE(1) << "Destroy StandardIMGlobal.\n";
        for (int i = 0; i < m_nr_modules; ++i) {
            if (m_modules [i].valid () && m_module_ime_funcs [i].finalize){
                m_module_ime_funcs [i].finalize ();
            }
        }

        delete [] m_module_ims;
        delete [] m_module_ime_funcs;
        delete [] m_modules;
    }

    int get_number_of_input_methods () const { return m_nr_ims; }

    StandardIMFactory * create_factory (int index) {
        SCIM_DEBUG_IMENGINE(1) << "create_factory " << index << ".\n";
        if (index >= 0 && index < m_nr_ims) {
            size_t count = 0;
            for (size_t i = 0; i < m_nr_modules; ++i) {
                if (count <= index && count + m_module_ims [i].size () > index) {
                    SCIM_DEBUG_IMENGINE(1) << "Success in module " << i << ".\n";
                    return new StandardIMFactory (i, (m_module_ims [i])[index - count]);
                }
                count += m_module_ims [i].size ();
            }
        }
        SCIM_DEBUG_IMENGINE(1) << "Fail.\n";
        return 0;
    }

    StandardIMInstance * find_instance (int id) {
        std::map <int, StandardIMInstance *>::iterator it = m_ics.find (id);
        if (it != m_ics.end ())
            return it->second;
        return 0;
    }

    void add_instance (StandardIMInstance *instance) {
        if (instance && instance->get_id () >= 0)
            m_ics [instance->get_id ()] = instance;
    }

    void remove_instance (StandardIMInstance *instance) {
        m_ics.erase (instance->get_id ());
    }

    IME_Bool create_input_context        (int                       module_id,
                                          IME_InputContext         *ic) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].create_input_context)
            return m_module_ime_funcs [module_id].create_input_context (ic);
        return IME_FALSE;
    }

    void     destroy_input_context       (int                       module_id,
                                          IME_InputContext         *ic) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].destroy_input_context)
            m_module_ime_funcs [module_id].destroy_input_context (ic);
    }

    IME_Bool process_key_event           (int                       module_id,
                                          const IME_InputContext   *ic,
                                          const IME_KeyEvent       *key) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].process_key_event)
            return m_module_ime_funcs [module_id].process_key_event (ic, key);
        return IME_FALSE;
    }

    void process_helper_event            (int                       module_id,
                                          const IME_InputContext    *ic,
                                          const char                *helper_uuid,
                                          const void                *buf,
                                          size_t                    bufsize) {
        if (module_id >=0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].process_helper_event)
             return m_module_ime_funcs [module_id].process_helper_event(ic, helper_uuid, buf, bufsize);
    }

    void     focus_in                    (int                       module_id,
                                          const IME_InputContext   *ic) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].focus_in)
            m_module_ime_funcs [module_id].focus_in (ic);
    }

    void     focus_out                   (int                       module_id,
                                          const IME_InputContext   *ic) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].focus_out)
            m_module_ime_funcs [module_id].focus_out (ic);
    }

    void     reset                       (int                       module_id,
                                          const IME_InputContext   *ic) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].reset)
            m_module_ime_funcs [module_id].reset (ic);
    }

    void     move_preedit_caret          (int                       module_id,
                                          const IME_InputContext   *ic,
                                          int                       position) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].move_preedit_caret)
            m_module_ime_funcs [module_id].move_preedit_caret (ic, position);
    }
 
    void     select_candidate            (int                       module_id,
                                          const IME_InputContext   *ic,
                                          int                       index) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].select_candidate)
            m_module_ime_funcs [module_id].select_candidate (ic, index);
    }

    void     previous_candidates_page    (int                       module_id,
                                          const IME_InputContext   *ic) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].previous_candidates_page)
            m_module_ime_funcs [module_id].previous_candidates_page (ic);
    }

    void     next_candidates_page        (int                       module_id,
                                          const IME_InputContext   *ic) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].next_candidates_page)
            m_module_ime_funcs [module_id].next_candidates_page (ic);
    }

    void     update_candidates_page_size (int                       module_id,
                                          const IME_InputContext   *ic,
                                          int                       size) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].update_candidates_page_size)
            m_module_ime_funcs [module_id].update_candidates_page_size (ic, size);
    }

    void     trigger_property            (int                       module_id,
                                          const IME_InputContext   *ic,
                                          const char               *property) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].trigger_property)
            m_module_ime_funcs [module_id].trigger_property (ic, property);
    }

/*    void     reload_config               (int                       module_id) {
        if (module_id >= 0 && module_id < m_nr_modules && m_module_ime_funcs [module_id].reload_config)
            m_module_ime_funcs [module_id].reload_config ();
    }
*/
};

static ConfigPointer __scim_config (0);

static StandardIMGlobal *__global;

extern "C" {
    void scim_module_init (void)
    {
        __global = new StandardIMGlobal;
    }

    void scim_module_exit (void)
    {
        delete __global;
    }

    uint32 scim_imengine_module_init (const ConfigPointer &config)
    {
        SCIM_DEBUG_IMENGINE(1) << "Initialize StandardIM Engine.\n";

        __scim_config = config;

        return __global->get_number_of_input_methods ();
    }

    IMEngineFactoryPointer scim_imengine_module_create_factory (uint32 engine)
    {
        return __global->create_factory ((int)engine);
    }
}

StandardIMFactory::StandardIMFactory (int module_id,
                                      const IME_InputMethod &input_method)
    : m_module_id (module_id),
      m_input_method (input_method)
{
    SCIM_DEBUG_IMENGINE(1) << "Create StandardIM Factory :\n";

    if (m_input_method.encoding && strlen (m_input_method.encoding) > 0 &&
        String (m_input_method.encoding) != "UTF-8" && m_iconv.set_encoding (m_input_method.encoding))
        m_utf8 = false;
    else
        m_utf8 = true;

    set_languages (String (m_input_method.languages));
}

StandardIMFactory::~StandardIMFactory ()
{
}

WideString
StandardIMFactory::get_name () const
{
    return convert_string (String (m_input_method.name));
}

WideString
StandardIMFactory::get_authors () const
{
    return convert_string (String (m_input_method.copyright));
}

WideString
StandardIMFactory::get_credits () const
{
    return WideString ();
}

WideString
StandardIMFactory::get_help () const
{
    return convert_string (String (m_input_method.help));
}

String
StandardIMFactory::get_uuid () const
{
    return String (m_input_method.uuid);
}

String
StandardIMFactory::get_icon_file () const
{
    return String (m_input_method.icon);
}

IMEngineInstancePointer
StandardIMFactory::create_instance (const String &encoding, int id)
{
    return new StandardIMInstance (this, encoding, id);
}

WideString
StandardIMFactory::convert_string (const String &str) const
{
    if (m_utf8) return utf8_mbstowcs (str);

    WideString wstr;

    m_iconv.convert (wstr, str);

    return wstr;
}

StandardIMInstance::StandardIMInstance (StandardIMFactory   *factory,
                                        const String        &encoding,
                                        int                  id)
    : IMEngineInstanceBase (factory, encoding, id),
      m_factory (factory),
      m_show_lookup_table (false),
      m_ok (false)
{

    SCIM_DEBUG_IMENGINE(1) << "Create StandardIM Instance: " << factory->get_uuid () << "\n";

    m_input_context.id = id;
    m_input_context.uuid = factory->m_input_method.uuid;
    m_input_context.charset = strdup (encoding.c_str ());
    m_input_context.private_data = 0;

    m_ok = __global->create_input_context (m_factory->get_module_id (), &m_input_context);

    if (m_ok)
        __global->add_instance (this);
}

StandardIMInstance::~StandardIMInstance ()
{
    __global->remove_instance (this);
    __global->destroy_input_context (m_factory->get_module_id (), &m_input_context);
    free ((char *) m_input_context.charset);
}

bool
StandardIMInstance::process_key_event (const KeyEvent& key)
{
    if (!m_ok) return false;

    SCIM_DEBUG_IMENGINE(2) << "process_key_event.\n";

    IME_KeyEvent imekey;

    imekey.code = key.code;
    imekey.mask = key.mask;
    imekey.unicode= key.get_unicode_code ();

    return __global->process_key_event (m_factory->get_module_id (), &m_input_context, &imekey);
}

void
StandardIMInstance::process_helper_event (const String &helper_uuid, const Transaction &trans)
{
    if (!m_ok) return;

    SCIM_DEBUG_IMENGINE(2) << "process_helper_event.\n";

    TransactionReader reader(trans);

    char *buf = NULL;
    size_t bufsize;
    int cmd;

    reader.get_command (cmd);

    if (cmd == SCIM_TRANS_CMD_HELPER_DATA) {
        reader.get_data(&buf, bufsize);

        __global->process_helper_event (m_factory->get_module_id (), &m_input_context, helper_uuid.c_str (), buf, bufsize);

        delete [] buf;
    }
}

void
StandardIMInstance::move_preedit_caret (unsigned int pos)
{
    if (!m_ok) return;

    SCIM_DEBUG_IMENGINE(2) << "move_preedit_caret.\n";

    __global->move_preedit_caret (m_factory->get_module_id (), &m_input_context, (int) pos);
}

void
StandardIMInstance::select_candidate (unsigned int item)
{
    if (!m_ok || !m_lookup_table.number_of_candidates ()) return;

    SCIM_DEBUG_IMENGINE(2) << "select_candidate.\n";
 
    __global->select_candidate (m_factory->get_module_id (), &m_input_context, (int)item);
}

void
StandardIMInstance::update_lookup_table_page_size (unsigned int page_size)
{
    if (!m_ok) return;

    SCIM_DEBUG_IMENGINE(2) << "update_lookup_table_page_size.\n";

    __global->update_candidates_page_size (m_factory->get_module_id (), &m_input_context, (int)page_size);
}

void
StandardIMInstance::lookup_table_page_up ()
{
    if (!m_ok) return;

    SCIM_DEBUG_IMENGINE(2) << "lookup_table_page_up.\n";

    __global->previous_candidates_page (m_factory->get_module_id (), &m_input_context);
}

void
StandardIMInstance::lookup_table_page_down ()
{
    if (!m_ok) return;

    SCIM_DEBUG_IMENGINE(2) << "lookup_table_page_down.\n";

    __global->next_candidates_page (m_factory->get_module_id (), &m_input_context);
}

void
StandardIMInstance::reset ()
{
    if (!m_ok) return;

    SCIM_DEBUG_IMENGINE(2) << "reset.\n";

    __global->reset (m_factory->get_module_id (), &m_input_context);
}

void
StandardIMInstance::focus_in ()
{
    if (!m_ok) return;

    SCIM_DEBUG_IMENGINE(2) << "focus_in.\n";

    hide_preedit_string ();
    hide_aux_string ();
    hide_lookup_table ();

    __global->focus_in (m_factory->get_module_id (), &m_input_context);
}

void
StandardIMInstance::focus_out ()
{
    if (!m_ok) return;

    SCIM_DEBUG_IMENGINE(2) << "focus_out.\n";

    __global->focus_out (m_factory->get_module_id (), &m_input_context);
}

void
StandardIMInstance::trigger_property (const String &property)
{
    if (!m_ok) return;

    SCIM_DEBUG_IMENGINE(2) << "trigger_property : " << property << "\n";

    __global->trigger_property (m_factory->get_module_id (), &m_input_context, property.c_str ());
}

static Attribute
convert_attribute (const IME_Attribute &ime_attr)
{
    Attribute attr ((unsigned int) ime_attr.start, (unsigned int) ime_attr.length);

    unsigned int val = 0;

    switch (ime_attr.type) {
        case IME_ATTR_DECORATION:
            if (ime_attr.value & IME_DECORATION_HIGHLIGHT)
                val |= SCIM_ATTR_DECORATE_HIGHLIGHT;
            if (ime_attr.value & IME_DECORATION_REVERSE)
                val |= SCIM_ATTR_DECORATE_REVERSE;
            if (ime_attr.value & IME_DECORATION_UNDERLINE)
                val |= SCIM_ATTR_DECORATE_UNDERLINE;
            attr.set_type (SCIM_ATTR_DECORATE);
            attr.set_value (val);
            break;
        case IME_ATTR_FOREGROUND_RGB:
            attr.set_type (SCIM_ATTR_FOREGROUND);
            attr.set_value (SCIM_RGB_COLOR(IME_RGB_COLOR_RED(ime_attr.value),IME_RGB_COLOR_GREEN(ime_attr.value),IME_RGB_COLOR_BLUE(ime_attr.value)));
            break;
        case IME_ATTR_BACKGROUND_RGB:
            attr.set_type (SCIM_ATTR_BACKGROUND);
            attr.set_value (SCIM_RGB_COLOR(IME_RGB_COLOR_RED(ime_attr.value),IME_RGB_COLOR_GREEN(ime_attr.value),IME_RGB_COLOR_BLUE(ime_attr.value)));
            break;
    }

    return attr;
}

void
StandardIMInstance::imm_show_preedit_string    (const IME_InputContext   *ic)
{
    if (ic && ic->id >= 0) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) inst->show_preedit_string ();
    }
}

void
StandardIMInstance::imm_hide_preedit_string    (const IME_InputContext   *ic)
{
    if (ic && ic->id >= 0) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) inst->hide_preedit_string ();
    }
}

void
StandardIMInstance::imm_update_preedit_string  (const IME_InputContext   *ic,
                                                const IME_String         *string)
{
    if (ic && ic->id >= 0 && string) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) {
            WideString str = inst->m_factory->convert_string (String (string->string));
            AttributeList attrs;
            if (string->nr_attributes > 0 && string->attributes) {
                for (int i = 0; i < string->nr_attributes; ++i)
                    attrs.push_back (convert_attribute (string->attributes [i]));
            }
            inst->update_preedit_string (str, attrs);
        }
    }
}

void
StandardIMInstance::imm_update_preedit_caret   (const IME_InputContext   *ic,
                                                int                       caret)
{
    if (ic && ic->id >= 0) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) inst->update_preedit_caret (caret);
    }
}

void
StandardIMInstance::imm_show_aux_string        (const IME_InputContext   *ic)
{
    if (ic && ic->id >= 0) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) inst->show_aux_string ();
    }
}

void
StandardIMInstance::imm_hide_aux_string        (const IME_InputContext   *ic)
{
    if (ic && ic->id >= 0) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) inst->hide_aux_string ();
    }
}

void
StandardIMInstance::imm_update_aux_string      (const IME_InputContext   *ic,
                                                const IME_String         *string)
{
    if (ic && ic->id >= 0 && string) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) {
            WideString str = inst->m_factory->convert_string (String (string->string));
            AttributeList attrs;
            if (string->nr_attributes > 0 && string->attributes) {
                for (int i = 0; i < string->nr_attributes; ++i)
                    attrs.push_back (convert_attribute (string->attributes [i]));
            }
            inst->update_aux_string (str, attrs);
        }
    }
}

void
StandardIMInstance::imm_show_candidates_list   (const IME_InputContext   *ic)
{
    if (ic && ic->id >= 0) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) {
            inst->show_lookup_table ();
            inst->m_show_lookup_table = true;
        }
    }
}

void
StandardIMInstance::imm_hide_candidates_list   (const IME_InputContext   *ic)
{
    if (ic && ic->id >= 0) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) {
            inst->hide_lookup_table ();
            inst->m_show_lookup_table = false;
        }
    }
}

void
StandardIMInstance::imm_update_candidates_list (const IME_InputContext   *ic,
                                                const IME_CandidatesList *candidates)
{
    if (ic && ic->id >= 0 && candidates) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) {
            inst->m_lookup_table.clear ();
            if (candidates->nr_candidates > 0 && candidates->candidates) {

                std::vector <WideString> labels;
                AttributeList attrs;
                WideString wstr;

                if ((candidates->page_state & IME_FIRST_PAGE) == 0)
                    inst->m_lookup_table.append_candidate ((ucs4_t) 0x20);

                for (int i = 0; i < candidates->nr_candidates; ++i) {
                    labels.push_back (inst->m_factory->convert_string (String (candidates->candidates [i].label)));

                    attrs.clear ();

                    for (int j = 0; j < candidates->candidates [i].content.nr_attributes; ++j)
                        attrs.push_back (convert_attribute (candidates->candidates [i].content.attributes [j]));

                    wstr = inst->m_factory->convert_string (String (candidates->candidates [i].content.string));
                    inst->m_lookup_table.append_candidate (wstr, attrs);
                }

                if ((candidates->page_state & IME_LAST_PAGE) == 0)
                    inst->m_lookup_table.append_candidate ((ucs4_t) 0x20);

                if ((candidates->page_state & IME_FIRST_PAGE) == 0) {
                    inst->m_lookup_table.set_page_size (1);
                    inst->m_lookup_table.page_down ();
                }

                inst->m_lookup_table.set_page_size (candidates->nr_candidates);
                inst->m_lookup_table.set_candidate_labels (labels);

                if (candidates->focused_candidate >= 0 && candidates->focused_candidate < candidates->nr_candidates)
                    inst->m_lookup_table.set_cursor_pos_in_current_page (candidates->focused_candidate);
            }

            inst->update_lookup_table (inst->m_lookup_table);
        }
    }
}

void
StandardIMInstance::imm_set_focused_candidate  (const IME_InputContext   *ic,
                                                int                       index)
{
    if (ic && ic->id >= 0) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst && index >= 0 && index < inst->m_lookup_table.get_current_page_size () && index != inst->m_lookup_table.get_cursor_pos_in_current_page ()) {
            inst->m_lookup_table.set_cursor_pos_in_current_page (index);
            if (inst->m_show_lookup_table) inst->update_lookup_table (inst->m_lookup_table);
        }
    }
}

void
StandardIMInstance::imm_commit_string          (const IME_InputContext   *ic,
                                                const char               *string)
{
    if (ic && ic->id >= 0 && string) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) inst->commit_string (inst->m_factory->convert_string (String (string)));
    }
}

void
StandardIMInstance::imm_register_properties    (const IME_InputContext   *ic,
                                                const IME_PropertiesList *properties)
{
    if (ic && ic->id >= 0 && properties) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) {
            PropertyList prop_list;
            if (properties->nr_properties > 0 && properties->properties) {
                Property prop;
                for (int i = 0; i < properties->nr_properties; ++i) {
                    prop.set_key (String (properties->properties [i].key));
                    prop.set_icon (String (properties->properties [i].icon));
                    prop.set_label (utf8_wcstombs (inst->m_factory->convert_string (String (properties->properties [i].label))));
                    prop.set_tip (utf8_wcstombs (inst->m_factory->convert_string (String (properties->properties [i].tip))));
                    prop.set_active ((properties->properties [i].state & IME_PROPERTY_ACTIVE) != 0);
                    prop.show ((properties->properties [i].state & IME_PROPERTY_VISIBLE) != 0);
                    prop_list.push_back (prop);
                }
            }
            inst->register_properties (prop_list);
        }
    }
}

void
StandardIMInstance::imm_update_property        (const IME_InputContext   *ic,
                                                const IME_Property       *property)
{
    if (ic && ic->id >= 0 && property) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        if (inst) {
            Property prop;
            prop.set_key (String (property->key));
            prop.set_icon (String (property->icon));
            prop.set_label (utf8_wcstombs (inst->m_factory->convert_string (String (property->label))));
            prop.set_tip (utf8_wcstombs (inst->m_factory->convert_string (String (property->tip))));
            prop.set_active ((property->state & IME_PROPERTY_ACTIVE) != 0);
            prop.show ((property->state & IME_PROPERTY_VISIBLE) != 0);
            inst->update_property (prop);
        }
    }
}

/*void
StandardIMInstance::imm_read_config            (const char               *key,
                                                char                     *buf,
                                                size_t                    buf_size)
{
    if (!__scim_config.null () && key && buf && buf_size > 0) {
        String str = __scim_config->read (String (STANDARD_IM_CONFIG_PREFIX) + String (key), String (""));
        strncpy (buf, str.c_str (), buf_size);
    }
}

void
StandardIMInstance::imm_write_config           (const char               *key,
                                                const char               *value)
{
    if (!__scim_config.null () && key && value) {
        __scim_config->write (String (STANDARD_IM_CONFIG_PREFIX) + String (key), String (value));
    }
}*/

void 
StandardIMInstance::imm_start_helper           (const IME_InputContext *ic,
                                                const char *helper_uuid)
{
    if (ic && ic->id >= 0 && helper_uuid) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        inst->start_helper (String (helper_uuid));
    }
                
}

void 
StandardIMInstance::imm_stop_helper            (const IME_InputContext *ic,
                                                const char *helper_uuid)
{
    if (ic && ic->id >= 0 && helper_uuid) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        inst->stop_helper (String (helper_uuid));
    }
}

void 
StandardIMInstance::imm_send_helper_event      (const IME_InputContext *ic,
                                                const char             *helper_uuid,
                                                const void             *buf,
                                                size_t                 bufsize)
{
    if (ic && ic->id >= 0 && helper_uuid) {
        StandardIMInstance * inst = __global->find_instance (ic->id);
        Transaction trans;
        
        trans.put_command (SCIM_TRANS_CMD_HELPER_DATA);
        trans.put_data ((char *)buf, bufsize);

        inst->send_helper_event (String (helper_uuid), trans);
    }
}

void 
StandardIMInstance::imm_beep                   (const IME_InputContext *ic)
{
    if (ic && ic->id >=0) {
        StandardIMInstance *inst = __global->find_instance (ic->id);
        inst->beep ();
    }
}

/*
vi:ts=4:nowrap:ai:expandtab
*/
