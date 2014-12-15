## Makefile.am -- Process this file with automake to produce Makefile.in
## Copyright (C) 2006 Qingyu Wang 
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2, or (at your option)
## any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

MAINTAINERCLEANFILES	= Makefile.in

INCLUDES		= -I$(top_builddir) \
	    		  -I$(top_srcdir) \
			  -I$(top_srcdir)/src \
			  -DSTANDARD_IM_MODULE_PATH=\"$(libdir)/chinese-standard/ime\" \
			  -DSTANDARD_HELPER_MODULE_PATH=\"$(libdir)/chinese-standard/helper\"

noinst_HEADERS		= ltdl.h\
			  standard_im.h \
			  standard_im_keys.h \
			  standard_im_module.h \
			  standard_im_imengine.h \
			  standard_helper_module.h \
			  standard_helper.h \
			  global.h

noinst_LTLIBRARIES	= libltdlc.la

libltdlc_la_SOURCES	= ltdl.c
libltdlc_la_LIBADD	= $(LIBADD_DL)

moduledir		= $(libdir)/scim-1.0/IMEngine
module_LTLIBRARIES	= chinese-standard-im.la

chinese_standard_im_la_SOURCES	= standard_im_module.cpp \
				  standard_im_imengine.cpp

chinese_standard_im_la_CFLAGS	= @SCIM_CFLAGS@ @SCIM_DEBUG_FLAGS@
chinese_standard_im_la_CXXFLAGS	= @SCIM_CFLAGS@ @SCIM_DEBUG_FLAGS@

chinese_standard_im_la_LDFLAGS	= -avoid-version \
			     	  -rpath $(moduledir) \
				  -module
				  @LIBTOOL_EXPORT_OPTIONS@ \
			 	  @SCIM_LIBS@
			  
chinese_standard_im_la_LIBADD	= libltdlc.la

standardhelperdir		= $(libdir)/scim-1.0/Helper
standardhelper_LTLIBRARIES	= chinese-standard-helper.la

chinese_standard_helper_la_SOURCES       = standard_helper_module.cpp \
					   standard_helper.cpp
				   
chinese_standard_helper_la_CFLAGS	= @SCIM_CFLAGS@ @SCIM_DEBUG_FLAGS@
chinese_standard_helper_la_CXXFLAGS	= @SCIM_CFLAGS@ @SCIM_DEBUG_FLAGS@

chinese_standard_helper_la_LDFLAGS	= -avoid-version \
					  -rpath $(standardhelperdir) \
					  -module
					  @LIBTOOL_EXPORT_OPTIONS@ \
			        	  @SCIM_LIBS@

chinese_standard_helper_la_LIBADD       = libltdlc.la

