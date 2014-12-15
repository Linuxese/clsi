/** @file standard_im_module.h
 * @brief definition of Module related classes.
 */

/* 
 * Copyright (c) 2006 Qingyu Wang <qwang@redhat.com>
 * Copyright (c) 2004 James Su <suzhe@turbolinux.com.cn>
 * Copyright (c) 2003 James Su <suzhe@turbolinux.com.cn>
 * Copyright (c) 2002 James Su <suzhe@turbolinux.com.cn>
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
 * $Id: scim_module.h,v 1.16 2004/02/06 07:53:15 suzhe Exp $
 */

#ifndef __STANDARD_IM_MODULE_H
#define __STANDARD_IM_MODULE_H

#include "standard_im.h"

using namespace scim;

class StandardIMModule 
{
    class StandardIMModuleImpl;
    StandardIMModuleImpl *m_impl;

    StandardIMModule (const StandardIMModule &);
    StandardIMModule & operator= (const StandardIMModule &);

public:
    StandardIMModule ();
    StandardIMModule (const String &name);
    ~StandardIMModule ();

    bool load (const String &name);
    bool unload ();

    bool valid () const;

    bool is_resident () const;
    bool make_resident () const;

    String get_path () const;

    bool ime_register_module (const IMM_Functions *imm, IME_Functions *ime);
};

int standard_im_get_module_list (std::vector <String>& mod_list);

#endif //__SCIM_MODULE_H

/*
vi:ts=4:ai:nowrap:expandtab
*/

