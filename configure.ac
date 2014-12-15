# Process this file with autoconf to produce a configure script.
AC_INIT(scim-chinese-standard, 0.0.2, qwang@redhat.com)
AC_CONFIG_SRCDIR([src/standard_im_imengine.h])

# Save this value here, since automake will set cflags and cxxflags later
cflags_set=${CFLAGS+set}
cppflags_set=${CPPFLAGS+set}

SCIM_STANDARD_IM_MAJOR_VERSION=0
SCIM_STANDARD_IM_MINOR_VERSION=1
SCIM_STANDARD_IM_MICRO_VERSION=1

SCIM_STANDARD_IM_VERSION=$SCIM_STANDARD_IM_MAJOR_VERSION.$SCIM_STANDARD_IM_MINOR_VERSION.$SCIM_STANDARD_IM_MICRO_VERSION

AC_SUBST(SCIM_STANDARD_IM_MAJOR_VERSION)
AC_SUBST(SCIM_STANDARD_IM_MINOR_VERSION)
AC_SUBST(SCIM_STANDARD_IM_MICRO_VERSION)
AC_SUBST(SCIM_STANDARD_IM_VERSION)

# Init automake stuff
AM_INIT_AUTOMAKE
AM_CONFIG_HEADER([config.h])

# Init libtool
AC_LIBTOOL_DLOPEN
AC_PROG_LIBTOOL
AC_LIB_LTDL
AC_SUBST(LIBTOOL_DEPS)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_LANG(C++)

AC_C_CONST
AC_TYPE_SIZE_T

# Checks for libraries.

SCIM_VERSION=0.99.0
STANDARD_IM_VERSION=0.3.9

PKG_CHECK_MODULES(SCIM,[scim >= $SCIM_VERSION])

AC_SUBST(SCIM_VERSION)

# Checks for header files.
AC_HEADER_STDC

# Checks for library functions.
AC_SUBST(ac_aux_dir)

# libtool option to control which symbols are exported
# right now, symbols starting with _ are not exported
LIBTOOL_EXPORT_OPTIONS='-export-symbols-regex "^[[^_]].*"'

# Extra args.
AC_ARG_ENABLE(debug,
	      [  --enable-debug     Turn on debugging],
	      [case "${enableval}" in
	       yes) debug=yes ;;
	       no)  debug=no ;;
	       *) AC_MSG_ERROR(bad value ${enableval} for --enable-debug) ;;
       	      esac],[debug=no])

if test "x$debug" = "xyes"; then
  test "$cflags_set" = set || CFLAGS="$CFLAGS -g"
  test "$cppflags_set" = set || CPPFLAGS="$CXXFLAGS -g"
  SCIM_DEBUG_FLAGS="-DENABLE_DEBUG=1"
else
  SCIM_DEBUG_FLAGS=""
fi
AC_SUBST(SCIM_DEBUG_FLAGS)

AC_CONFIG_FILES([Makefile
		 src/Makefile
		 scim-chinese-standard.spec])
AC_OUTPUT
