## Process this file with automake to produce Makefile.in

SUBDIRS = \
	wxServDisc



AM_CPPFLAGS = \
	$(WX_CXXFLAGS)

AM_CFLAGS =\
	 -Wall \
	 -g \
	 $(WX_CPPFLAGS)

bin_PROGRAMS = sdwrap

sdwrap_SOURCES = \
	SdwrapApp.cpp   \
	SdwrapApp.h   \
	dfltcfg.h \
	gui/FrameMain.cpp \
	gui/FrameMain.h \
	gui/MyFrameMain.cpp \
	gui/MyFrameMain.h \
	gui/DialogSettings.cpp \
	gui/DialogSettings.h \
	gui/MyDialogSettings.cpp \
	gui/MyDialogSettings.h \
	gui/bitmapFromMem.h\
	gui/res/about.png.h \
	gui/res/add.png.h \
	gui/res/info.png.h \
	gui/res/remove.png.h \
	gui/res/icon.xpm 


if MINGW
sdwrap_SOURCES += gui/winres.rc
.rc.o:
	 $(WX_RESCOMP) -o $@ $<
endif


sdwrap_LDFLAGS = 

sdwrap_LDADD = \
	wxServDisc/libwxservdisc.la \
	$(WX_LIBS)



