/** @file standard_helper.cpp
 */

/*Copyright (c) 2006 Qingyu Wang <qwang@redhat.com>

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
*/


#define Uses_SCIM_UTILITY
#define Uses_SCIM_OBJECT
#define Uses_SCIM_POINTER
#define Uses_SCIM_EVENT
#define Uses_SCIM_HELPER
#define Uses_SCIM_CONFIG_BASE
#define Uses_STL_MAP

#ifdef HAVE_CONFIG_H
  #include <config.h>
#endif

#include <scim.h>
#include "standard_helper.h"
#include "standard_helper_module.h"
#include "global.h"

#define scim_module_init chinese_standard_helper_LTX_scim_module_init
#define scim_module_exit chinese_standard_helper_LTX_scim_module_exit
#define scim_helper_module_number_of_helpers chinese_standard_helper_LTX_scim_helper_module_number_of_helpers
#define scim_helper_module_get_helper_info chinese_standard_helper_LTX_scim_helper_module_get_helper_info
#define scim_helper_module_run_helper chinese_standard_helper_LTX_scim_helper_module_run_helper

#define SCIM_TRANS_CMD_HELPER_DATA  10000 + 1234

using namespace scim;

static void slot_attach_input_context (const HelperAgent *, int ic, const String &ic_uuid);
static void slot_detach_input_context (const HelperAgent *, int ic, const String &ic_uuid);
static void slot_update_screen (const HelperAgent *, int ic, const String &ic_uuid, int screen); 
static void slot_update_spot_location (const HelperAgent *, int ic, const String &ic_uuid, int x, int y);
static void slot_process_ime_event (const HelperAgent *, int ic, const String &ic_uuid, const Transaction &trans); 
static void slot_trigger_property (const HelperAgent *, int ic, const String &ic_uuid, const String &property);


static int         m_module_id = -1;
static HelperAgent m_helper_agent;

class StandardHelperGlobal
{
    int                                  m_nr_modules;

    StandardHelperModule                 *m_modules;

    IME_Helper_Functions                 *m_module_helper_funcs;

    IME_Helper_Info                      *m_module_helpers;


public:
    StandardHelperGlobal ()
        : m_nr_modules (0),
          m_modules (0),
          m_module_helper_funcs (0),
          m_module_helpers (0) {

	IME_Helper_Info info;
	
        std::vector <String> mod_list;

        m_nr_modules = standard_helper_get_module_list (mod_list);

        if (m_nr_modules <= 0) return;

        m_modules = new StandardHelperModule [m_nr_modules];
        m_module_helper_funcs = new IME_Helper_Functions [m_nr_modules];
        m_module_helpers = new IME_Helper_Info [m_nr_modules];

        for (int i = 0; i < m_nr_modules; ++i) {
            if (m_modules [i].load (mod_list [i]) &&
                m_modules [i].ime_helper_register_module (&__imm_helper_functions, &(m_module_helper_funcs [i]), &info)) {
                if (m_module_helper_funcs [i].run &&
                    m_module_helper_funcs [i].finalize){
		    m_module_helpers [i].uuid = info.uuid;
		    m_module_helpers [i].encoding = info.encoding;
		    m_module_helpers [i].name = info.name;
		    m_module_helpers [i].description = info.description;
		    m_module_helpers [i].icon = info.icon;
		    m_module_helpers [i].options = info.options;
		    continue;
		}
                m_modules [i].unload ();
	    }
	}
    }

    ~StandardHelperGlobal () {
        for (int i = 0; i < m_nr_modules; ++i) {
            if (m_modules [i].valid () && m_module_helper_funcs [i].finalize)
                m_module_helper_funcs [i].finalize ();
        }

        delete [] m_module_helpers;
        delete [] m_module_helper_funcs;
        delete [] m_modules;
    }
    
    unsigned int get_number_of_helpers () {
	return m_nr_modules;
    }

    bool get_helper_info             (unsigned int             idx, 
	                              HelperInfo               &info) {
	if (idx < m_nr_modules) {
	    info.uuid = String (m_module_helpers [idx].uuid); 
	    info.name = String (m_module_helpers [idx].name);
	    info.icon = String (m_module_helpers [idx].icon);
	    info.description = String (m_module_helpers [idx].description);
	    info.option = m_module_helpers [idx].options; 
	    return true;
	}
	
	return false;
    }

    void run_helper                    (const char              *uuid,
	                                const char              *display) {
	int i;
	for (i = 0;i < m_nr_modules; i++){
	   if (!strcmp (m_module_helpers [i].uuid, uuid) && m_module_helper_funcs [i].run) {
	       m_module_id = i;
	       
	       HelperInfo info;
	       if (get_helper_info(i, info)){
		   m_helper_agent.open_connection (info, display);
	       	   m_helper_agent.signal_connect_update_screen (slot (slot_update_screen));
	           m_helper_agent.signal_connect_update_spot_location (slot (slot_update_spot_location));
	           m_helper_agent.signal_connect_trigger_property (slot (slot_trigger_property));
	           m_helper_agent.signal_connect_process_imengine_event (slot (slot_process_ime_event));
	           m_module_helper_funcs [i].run(display);
	       }
	       break;
	   }
	} 
    }
    
    void attach_input_context           (int                       ic, 
	                                 const char               *ic_uuid) {
	if (m_module_id >= 0 && m_module_id < m_nr_modules && m_module_helper_funcs [m_module_id].attach_input_context)
	    m_module_helper_funcs [m_module_id].attach_input_context (ic, ic_uuid);
	
    }

    void detach_input_context           (int                       ic, 
	                                 const char               *ic_uuid) {
	if (m_module_id >= 0 && m_module_id < m_nr_modules && m_module_helper_funcs [m_module_id].detach_input_context)
	    m_module_helper_funcs [m_module_id].detach_input_context (ic, ic_uuid);
	
    }

    void update_screen                  (int                       ic,
	                                 const char               *ic_uuid,
					 const char               *screen) {
	if (m_module_id >= 0 && m_module_id < m_nr_modules && m_module_helper_funcs [m_module_id].update_screen)
	    m_module_helper_funcs [m_module_id].update_screen(ic, ic_uuid, screen);
	
    }

    void update_spot_location           (int                       ic,
	                                 const char               *ic_uuid,
					 int                       x,
					 int                       y) {
	if (m_module_id >= 0 && m_module_id < m_nr_modules && m_module_helper_funcs [m_module_id].update_spot_location)
	    m_module_helper_funcs [m_module_id].update_spot_location(ic, ic_uuid, x, y);
    }

    void trigger_property               (int                       ic,
                                         const char               *ic_uuid,
                                         const char               *property) {
	if (m_module_id >= 0 && m_module_id < m_nr_modules && m_module_helper_funcs [m_module_id].trigger_property)
	    m_module_helper_funcs [m_module_id].trigger_property(ic, ic_uuid, property);
    }

    void process_ime_event              (int                        ic,
                                         const char                *ic_uuid,
                                         const void                *buf,
                                         size_t                     len) {
	if (m_module_id >= 0 && m_module_id < m_nr_modules && m_module_helper_funcs [m_module_id].process_ime_event)
	    m_module_helper_funcs [m_module_id].process_ime_event(ic, ic_uuid, buf, len);
    }
};


static StandardHelperGlobal *g_helper;

extern "C" {
    void scim_module_init (void) {
	
	g_helper = new StandardHelperGlobal;
    }

    void scim_module_exit (void) { 

	delete g_helper;
    }

    unsigned int scim_helper_module_number_of_helpers (void) {
	
        return g_helper->get_number_of_helpers();
    }

    bool scim_helper_module_get_helper_info (unsigned int idx, HelperInfo &info) {

	return g_helper->get_helper_info(idx, info);
    }

    void scim_helper_module_run_helper (const String &uuid, const ConfigPointer &config, const String &display) {

	g_helper->run_helper(uuid.c_str (), display.c_str ());
    }
}

static void slot_attach_input_context (const HelperAgent *, int ic, const String &ic_uuid) 
{
    g_helper->attach_input_context (ic, ic_uuid.c_str ());
}

static void slot_detach_input_context (const HelperAgent *, int ic, const String &ic_uuid)
{
    g_helper->detach_input_context (ic, ic_uuid.c_str ());
}

static void slot_update_screen (const HelperAgent *, int ic, const String &ic_uuid, int screen) 
{
    char scr [33];

    snprintf(scr, 33, "%d", screen);
    g_helper->update_screen(ic, ic_uuid.c_str (), scr);
}

static void slot_update_spot_location (const HelperAgent *, int ic, const String &ic_uuid, int x, int y) 
{
    g_helper->update_spot_location(ic, ic_uuid.c_str (), x, y);
}

static void slot_process_ime_event (const HelperAgent *, int ic, const String &ic_uuid, const Transaction &trans) 
{  
    TransactionReader reader(trans);
    
    char *buf = NULL;
    size_t bufsize;
    int cmd;

    reader.get_command (cmd); 
    if (cmd == SCIM_TRANS_CMD_HELPER_DATA) {
	reader.get_data (&buf, bufsize);

       	g_helper->process_ime_event(ic, ic_uuid.c_str (), buf, bufsize);
	delete [] buf;
    }
}

static void slot_trigger_property (const HelperAgent *, int ic, const String &ic_uuid, const String &property) 
{
    g_helper->trigger_property(ic, ic_uuid.c_str (), property.c_str ());

}

static int get_connection_number (void)
{
    return m_helper_agent.get_connection_number();
}

static void filter_event (void) 
{
    HelperAgent *agent = static_cast<HelperAgent *> (&m_helper_agent);
    
    if (agent && agent->has_pending_event ())
	agent->filter_event ();
}

static void register_properties (const IME_PropertiesList *propertiesList) 
{
    PropertyList prop_list;
    
    if (propertiesList->nr_properties > 0 && propertiesList->properties){
	for (int i = 0; i < propertiesList->nr_properties; i++){
		Property prop;
       		prop.set_key (String (propertiesList->properties [i].key));
		prop.set_label (String (propertiesList->properties [i].label));
    		prop.set_icon (String (propertiesList->properties [i].icon));
    		prop.set_tip (String (propertiesList->properties [i].tip));
    		prop.set_active ((propertiesList->properties [i].state & IME_PROPERTY_ACTIVE) != 0);
    		prop.show ((propertiesList->properties [i].state & IME_PROPERTY_VISIBLE) != 0);
		prop_list.push_back (prop);
    	}
    }
    
    m_helper_agent.register_properties(prop_list);
}

static void update_property (const IME_Property *property) 
{
    Property prop;
    prop.set_key (String (property->key));
    prop.set_label (String (property->label));
    prop.set_icon (String (property->icon));
    prop.set_tip (String (property->tip));
    prop.set_active ((property->state & IME_PROPERTY_ACTIVE) != 0);
    prop.show ((property->state & IME_PROPERTY_VISIBLE) != 0);
    
    m_helper_agent.update_property(prop);
}

static void send_ime_event (int ic, const char *ic_uuid, const void *buf, size_t bufsize) 
{
    Transaction trans;
    
    trans.put_command (SCIM_TRANS_CMD_HELPER_DATA);
    trans.put_data ((const char *)buf, bufsize);

    m_helper_agent.send_imengine_event(ic, String(ic_uuid), trans);
}

static void send_key_event (int ic, const char *ic_uuid, const IME_KeyEvent *imekey) 
{
    KeyEvent key (imekey->code, imekey->mask);

    if (!key.empty())
	m_helper_agent.send_key_event(ic, String(ic_uuid), key);
}

static void commit_string (int ic, const char *ic_uuid, const char *string) 
{
    m_helper_agent.commit_string (ic, String(ic_uuid), utf8_mbstowcs (string));
}

static void forward_key_event (int ic, const char *ic_uuid, const IME_KeyEvent *imekey) 
{
    KeyEvent key (imekey->code, imekey->mask);

    if (!key.empty())
	m_helper_agent.forward_key_event (ic, String(ic_uuid), key);
}

