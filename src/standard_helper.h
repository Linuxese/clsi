/** @file standard_helper.h
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
 *
*/

#ifndef __STANDARD_HELPER_H
#define __STANDARD_HELPER_H

#include "standard_im.h"

static int get_connection_number (void);
static void filter_event (void);
static void register_properties (const IME_PropertiesList *propertiesList);
static void update_property (const IME_Property *property);
static void send_ime_event (int ic, const char *ic_uuid, const void *buf, size_t bufsize);
static void send_key_event (int ic, const char *ic_uuid, const IME_KeyEvent *imekey);
static void commit_string (int ic, const char *ic_uuid, const char *string);
static void forward_key_event (int ic, const char *ic_uuid, const IME_KeyEvent *imekey);


IMM_Helper_Functions __imm_helper_functions = {
    get_connection_number,
    filter_event,
    register_properties,
    update_property,
    send_ime_event,
    send_key_event,
    commit_string,
    forward_key_event
};

#endif
