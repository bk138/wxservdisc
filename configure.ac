dnl Process this file with autoconf to produce a configure script.
dnl Created by Anjuta application wizard.

# init
AC_INIT(wxServDisc, 0.3)
AM_INIT_AUTOMAKE([subdir-objects foreign])
AC_CONFIG_MACRO_DIR([m4])

# if this macro is defined, use it
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

# the file where results of system scan go, e.g. is there some header file or not
AM_CONFIG_HEADER(config.h)



AC_CANONICAL_HOST
case $host_os in
     darwin*)
	HOST_IS_DARWIN="yes"
	;;
     *mingw32*)
	HOST_IS_WINDOWS="yes"
	;;
     *)
	HOST_IS_DARWIN="no"
	HOST_IS_WINDOWS="no"
	;;
esac




AM_CONDITIONAL(MINGW, [ test "$HOST_IS_WINDOWS" = "yes" ])
AM_CONDITIONAL(DARWIN, [ test "$HOST_IS_DARWIN" = "yes" ])



WXCONFIG=wx-config
AC_ARG_WITH(wx-config,
[[  --with-wx-config=FILE
    Use the given path to wx-config when determining
    wxWidgets configuration; defaults to "wx-config"]],
[
    if test "$withval" != "yes" -a "$withval" != ""; then
        WXCONFIG=$withval
    fi
])


dnl Check if we have enabled debug support.
AC_MSG_CHECKING(whether to enable debugging)
AC_ARG_ENABLE(debug, [  --enable-debug          enable debug build [[default=no]]],, enable_debug="no")
if test "x$enable_debug" = "xyes"; then
	CXXFLAGS="$CXXFLAGS -Wall -Wextra -Wno-unused-parameter"
	WXCONFIG="$WXCONFIG --debug=yes"	
	AC_MSG_RESULT(yes)
else
	WXCONFIG="$WXCONFIG --debug=no"	
	AC_MSG_RESULT(no)
fi


AC_MSG_CHECKING([wxWidgets version])
if wxversion=`$WXCONFIG --version`; then
    AC_MSG_RESULT([$wxversion])
else
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([wxWidgets is required. Try --with-wx-config.])
fi

dnl check for universal wx lib
if test "$HOST_IS_DARWIN" = "yes"; then
   AC_MSG_CHECKING([whether wxWidgets is a universal lib])
   if test ! -z "`$WXCONFIG --libs | grep "arch i386" 2>/dev/null`" \
        -a ! -z "`$WXCONFIG --libs | grep "arch ppc" 2>/dev/null`"; then
     CC="gcc -arch i386 -arch ppc"
     CXX="g++ -arch i386 -arch ppc"
     CPP="cpp"
     CXXCPP="cpp"
     AC_MSG_RESULT([yes])
   else
     AC_MSG_RESULT([no])
   fi
fi


 
WX_CPPFLAGS="`$WXCONFIG --cppflags`"
WX_CXXFLAGS="`$WXCONFIG --cxxflags`"
WX_LIBS="`$WXCONFIG --libs`"
WX_RESCOMP="`$WXCONFIG --rescomp`"

 
AC_SUBST(WX_CPPFLAGS)
AC_SUBST(WX_CXXFLAGS)
AC_SUBST(WX_LIBS)
AC_SUBST(WX_RESCOMP)

AC_ISC_POSIX
AC_PROG_CPP
AC_PROG_CC
AM_PROG_CC_STDC
AM_PROG_CC_C_O
AC_PROG_CXX
AC_HEADER_STDC
AC_LIBTOOL_WIN32_DLL
AM_PROG_LIBTOOL


AC_OUTPUT([
Makefile
src/Makefile
src/wxServDisc/Makefile
src/sdwrap/Makefile
])
