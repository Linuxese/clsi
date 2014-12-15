/** @file standard_im_imengine.h
 */

/* 
 * Smart Common Input Method
 * 
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

#if !defined (__STANDARD_IM_IMENGINE_H)
#define __STANDARD_IM_IMENGINE_H

#include "standard_im.h"

using namespace scim;

class StandardIMFactory : public IMEngineFactoryBase
{
    int             m_module_id;
    IME_InputMethod m_input_method;
    IConvert        m_iconv;

    bool            m_utf8;

    friend class StandardIMInstance;

public:
    StandardIMFactory (int module_id, const IME_InputMethod &input_method);

    virtual ~StandardIMFactory ();

    virtual WideString  get_name () const;
    virtual WideString  get_authors () const;
    virtual WideString  get_credits () const;
    virtual WideString  get_help () const;
    virtual String      get_uuid () const;
    virtual String      get_icon_file () const;

    virtual IMEngineInstancePointer create_instance (const String& encoding, int id = -1);

    int get_module_id () const { return m_module_id; }

    WideString convert_string (const String &str) const;
};

class StandardIMInstance : public IMEngineInstanceBase
{
    StandardIMFactory *m_factory;
    IME_InputContext   m_input_context;
    CommonLookupTable  m_lookup_table;
    bool               m_show_lookup_table;

    bool               m_ok;

public:
    StandardIMInstance (StandardIMFactory   *factory,
                        const String        &encoding,
                        int                  id = -1);

    virtual ~StandardIMInstance ();

    virtual bool process_key_event (const KeyEvent& key);
    virtual void process_helper_event (const String &helper_uuid, const Transaction &trans);
    virtual void move_preedit_caret (unsigned int pos);
    virtual void select_candidate (unsigned int item);
    virtual void update_lookup_table_page_size (unsigned int page_size);
    virtual void lookup_table_page_up ();
    virtual void lookup_table_page_down ();
    virtual void reset ();
    virtual void focus_in ();
    virtual void focus_out ();
    virtual void trigger_property (const String &property);

    int get_module_id () const { return m_factory->m_module_id; }

public:
    static void imm_show_preedit_string             (const IME_InputContext   *ic);

    static void imm_hide_preedit_string             (const IME_InputContext   *ic);

    static void imm_update_preedit_string           (const IME_InputContext   *ic,
                                                     const IME_String         *string);

    static void imm_update_preedit_caret            (const IME_InputContext   *ic,
                                                     int                       caret);

    static void imm_show_aux_string                 (const IME_InputContext   *ic);

    static void imm_hide_aux_string                 (const IME_InputContext   *ic);

    static void imm_update_aux_string               (const IME_InputContext   *ic,
                                                     const IME_String         *string);

    static void imm_show_candidates_list            (const IME_InputContext   *ic);

    static void imm_hide_candidates_list            (const IME_InputContext   *ic);

    static void imm_update_candidates_list          (const IME_InputContext   *ic,
                                                     const IME_CandidatesList *candidates);

    static void imm_set_focused_candidate           (const IME_InputContext   *ic,
                                                     int                       index);

    static void imm_commit_string                   (const IME_InputContext   *ic,
                                                     const char               *string);

    static void imm_register_properties             (const IME_InputContext   *ic,
                                                     const IME_PropertiesList *properties);

    static void imm_update_property                 (const IME_InputContext   *ic,
                                                     const IME_Property       *property);

/*    static void imm_read_config                     (const char               *key,
                                                     char                     *buf,
                                                     size_t                    buf_size);

    static void imm_write_config                    (const char               *key,
                                                     const char               *value);
    
*/
    static void imm_start_helper                    (const IME_InputContext   *ic,
                                                     const char               *helper_uuid);
    
    static void imm_stop_helper                     (const IME_InputContext   *ic,
                                                     const char               *helper_uuid);

    static void imm_send_helper_event               (const IME_InputContext   *ic,
                                                     const char               *helper_uuid,
                                                     const void               *buf,
                                                     size_t                   bufsize);

    static void imm_beep                                (const IME_InputContext   *ic);
};

#endif
/*
vi:ts=4:nowrap:ai:expandtab
*/
