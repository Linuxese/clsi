/*@file standard_helper_module.cpp
* @This file is the implementation of module related class.
*/

/*Copyright (c) 2006 Qingyu Wang <qwang@redhat.com>
 *Copyright (c) 2002-2005 James Su <suzhe@tsinghua.org.cn>
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
 */

#define Uses_STL_ALGORITHM

#if HAVE_CONFIG_H
#include <config.h>
#endif

#include <scim.h>
#include "standard_helper_module.h"
#include "ltdl.h"
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef STANDARD_HELPER_MODULE_PATH
  #define STANDARD_HELPER_MODULE_PATH "/usr/lib/chinese-standard/helper"
#endif

#ifndef STANDARD_HELPER_BINARY_VERSION
  #define STANDARD_HELPER_BINARY_VERSION "1.0.0"
#endif

using namespace scim;

typedef IME_Bool (*IMEHelperRegisterModuleFunc) (const IMM_Helper_Functions *imm, 
                                                IME_Helper_Functions *ime,
                                                IME_Helper_Info *helper_info);

struct StandardHelperModule::StandardHelperModuleImpl
{
    lt_dlhandle handle;
    IMEHelperRegisterModuleFunc ime_helper_register_module;
    String path;
    String name;

    StandardHelperModuleImpl () : handle (0), ime_helper_register_module (0) { }
};

static std::vector <IMEHelperRegisterModuleFunc> __standard_helper_modules;

static void
_standard_helper_get_module_paths (std::vector <String> &paths)
{
    const char *module_path_env;

   paths.clear ();

    module_path_env = getenv ("STANDARD_HELPER_MODULE_PATH");

    if (module_path_env && String (module_path_env) != String (STANDARD_HELPER_MODULE_PATH))
        paths.push_back (String (module_path_env));

    paths.push_back (String (STANDARD_HELPER_MODULE_PATH));
}

int
standard_helper_get_module_list (std::vector <String>& mod_list)
{
    std::vector<String> paths;

    _standard_helper_get_module_paths (paths);

    mod_list.clear ();

    for (std::vector<String>::iterator i = paths.begin (); i!= paths.end (); ++i) {
        DIR *dir = opendir (i->c_str ());

        if (dir) {
            struct dirent *file = readdir (dir);
            while (file) {
                struct stat filestat;
                String absfn = *i + String (SCIM_PATH_DELIM_STRING) + file->d_name;
                stat (absfn.c_str (), &filestat);
                if (S_ISREG (filestat.st_mode)) {
                    std::vector<String> vec;
                    scim_split_string_list (vec, String (file->d_name), '.');
                    mod_list.push_back (vec [0]);
                }
                file = readdir (dir);
            }
            closedir (dir);
        }
    }
    std::sort (mod_list.begin (), mod_list.end ());
    mod_list.erase (std::unique (mod_list.begin(), mod_list.end()), mod_list.end());
    return mod_list.size ();
}

StandardHelperModule::StandardHelperModule ()
    : m_impl (new StandardHelperModuleImpl)
{
    lt_dlinit ();
}

StandardHelperModule::StandardHelperModule (const String &name)
    : m_impl (new StandardHelperModuleImpl)
{
    lt_dlinit ();
    load (name);
}

StandardHelperModule::~StandardHelperModule ()
{
    unload ();
    lt_dlexit ();
    delete m_impl;
}

static String
_concatenate_ltdl_prefix (const String &name, const String &symbol)
{
    String prefix (name);

    for (size_t i=0; i<prefix.length (); i++)
        if (!isalnum ((int)prefix[i]))
            prefix[i] = '_';

    return prefix + String ("_LTX_") + symbol;
}

bool
StandardHelperModule::load (const String &name)
{
    // If cannot unload original module (it's resident), then return false.
    if (is_resident ())
        return false;

    std::vector <String> paths;
    std::vector <String>::iterator it; 

    String module_path;

    lt_dlhandle    new_handle;

    IMEHelperRegisterModuleFunc new_ime_helper_register_module;

    _standard_helper_get_module_paths (paths);

    for (it = paths.begin (); it != paths.end (); ++it) {
        module_path = *it + String (SCIM_PATH_DELIM_STRING) + name;
        new_handle = lt_dlopenext (module_path.c_str ());
        if (new_handle)
            break;
    }

    if (!new_handle) {
        new_handle = lt_dlopenext (name.c_str ());
        module_path = String ();
    }

    if (!new_handle)
        return false;

    String symbol;

    // Try to load the symbol scim_module_init
    symbol = "ime_helper_register_module";
    new_ime_helper_register_module = (IMEHelperRegisterModuleFunc) lt_dlsym (new_handle, symbol.c_str ());

    // If symbol load failed, try to add LTX prefix and load again.
    // This will occurred when name.la is missing.
    if (!new_ime_helper_register_module) {
        symbol = _concatenate_ltdl_prefix (name, symbol);
        new_ime_helper_register_module = (IMEHelperRegisterModuleFunc) lt_dlsym (new_handle, symbol.c_str ());

        // Failed again? Try to prepend a under score to the symbol name.
        if (!new_ime_helper_register_module) {
            symbol.insert (symbol.begin (),'_');
            new_ime_helper_register_module = (IMEHelperRegisterModuleFunc) lt_dlsym (new_handle, symbol.c_str ());
        }
    }

    // Could not load the module!
    if (!new_ime_helper_register_module) {
        lt_dlclose (new_handle);
        return false;
    }

    //Check if the module is already loaded.
    if (std::find (__standard_helper_modules.begin (), __standard_helper_modules.end (), new_ime_helper_register_module)
        != __standard_helper_modules.end ()) {
        lt_dlclose (new_handle);
        return false;
    }

    if (unload ()) {
        __standard_helper_modules.push_back (new_ime_helper_register_module);

        m_impl->handle = new_handle;
        m_impl->ime_helper_register_module = new_ime_helper_register_module;
        m_impl->path   = module_path;
        m_impl->name   = name;

        return true;
    }

    lt_dlclose (new_handle);

    return false;
}

bool
StandardHelperModule::unload ()
{
    if (!m_impl->handle)
        return true;

    if (is_resident ())
        return false;

    lt_dlclose (m_impl->handle);

    std::vector <IMEHelperRegisterModuleFunc>::iterator it =
        std::find (__standard_helper_modules.begin (), __standard_helper_modules.end (), m_impl->ime_helper_register_module);

    if (it != __standard_helper_modules.end ())
        __standard_helper_modules.erase (it);

    m_impl->handle = 0;
    m_impl->ime_helper_register_module = 0;
    m_impl->path   = String ();
    m_impl->name   = String ();

    return true;
}

bool
StandardHelperModule::make_resident () const
{
    if (m_impl->handle) {
        return lt_dlmakeresident (m_impl->handle) == 0;
    }
    return false;
}

bool
StandardHelperModule::is_resident () const
{
    if (m_impl->handle) {
        return lt_dlisresident (m_impl->handle) == 1;
    }
    return false;
}

bool
StandardHelperModule::valid () const
{
    return (m_impl->handle && m_impl->ime_helper_register_module);
}

String
StandardHelperModule::get_path () const
{
    return m_impl->path;
}

bool
StandardHelperModule::ime_helper_register_module (const IMM_Helper_Functions *imm_helper, 
                                                  IME_Helper_Functions *ime_helper,
                                                  IME_Helper_Info      *helper_info)
{
    if (valid ())
        return m_impl->ime_helper_register_module (imm_helper, ime_helper, helper_info) == IME_TRUE;

    return IME_FALSE;
}

