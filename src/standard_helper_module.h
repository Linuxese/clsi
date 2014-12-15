/** @file standard_heler_module.h
 * @brief definition of Module related classes.
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
 */

#ifndef __STANDARD_HELPER_MODULE_H
#define __STANDARD_HELPER_MODULE_H

#include "standard_im.h"

using namespace scim;

class StandardHelperModule 
{
    class StandardHelperModuleImpl;
    StandardHelperModuleImpl *m_impl;

    StandardHelperModule (const StandardHelperModule &);
    StandardHelperModule & operator= (const StandardHelperModule &);

public:
    StandardHelperModule ();
    StandardHelperModule (const String &name);
    ~StandardHelperModule ();

    bool load (const String &name);
    bool unload ();

    bool valid () const;

    bool is_resident () const;
    bool make_resident () const;

    String get_path () const;

    bool ime_helper_register_module (const IMM_Helper_Functions *imm_helper, 
                                     IME_Helper_Functions       *ime_helper,
                                     IME_Helper_Info            *helper_info);
};

int standard_helper_get_module_list (std::vector <String>& mod_list);

#endif

/*
vi:ts=4:ai:nowrap:expandtab
*/

