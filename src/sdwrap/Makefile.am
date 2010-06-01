## Process this file with automake to produce Makefile.in



AM_CPPFLAGS = \
	$(WX_CXXFLAGS)

AM_CFLAGS =\
	 -Wall \
	 -g \
	 $(WX_CPPFLAGS)

Applicationsdir = $(datadir)/applications/
Applications_DATA = sdwrap.desktop

pixmapdir = $(datadir)/pixmaps
pixmap_DATA = gui/res/sdwrap.xpm


EXTRA_DIST = $(Applications_DATA) \
             $(pixmap_DATA)


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
	gui/res/sdwrap.xpm \
	gui/res/icon.icns


if MINGW
sdwrap_SOURCES += gui/winres.rc
.rc.o:
	 $(WX_RESCOMP) -o $@ $<
endif


sdwrap_LDFLAGS = 

sdwrap_LDADD = \
	../wxServDisc/libwxservdisc.la \
	$(WX_LIBS)


if DARWIN
bundle_contents = SDWrap.app/Contents
appbundle: sdwrap
	mkdir -p $(bundle_contents)/MacOS
	mkdir -p $(bundle_contents)/Resources
	echo "APPL????" > $(bundle_contents)/PkgInfo
	$(LIBTOOL) --mode install $(INSTALL_PROGRAM) $< $(CURDIR)/$(bundle_contents)/MacOS/
	cp gui/res/icon.icns $(bundle_contents)/Resources
	cp README  $(bundle_contents)/Resources
	cp ../../NEWS    $(bundle_contents)/Resources
	cp ../../COPYING $(bundle_contents)/Resources
	cp ../../AUTHORS $(bundle_contents)/Resources
	echo \
	"<?xml version="1.0" encoding="UTF-8"?>\
	<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd"\
	<plist version="1.0">\
	<dict>\
	<key>CFBundleDevelopmentRegion</key>\
	<string>English</string>\
	<key>CFBundleExecutable</key>\
	<string>sdwrap</string>\
	<key>CFBundleIconFile</key>\
	<string>icon.icns</string>\
	<key>CFBundleGetInfoString</key>\
	<string>SDWrap @PACKAGE_VERSION@, © Christian Beier (dontmind@freeshell.org), 2008-2010 </string>\
	<key>CFBundleName</key>  \
	<string>SDWrap</string> \
	<key>CFBundlePackageType</key> \
	<string>APPL</string>          \
	<key>CFBundleShortVersionString</key> \
	<string>@PACKAGE_VERSION@</string> \
	<key>CFBundleVersion</key> \
	<string>@PACKAGE_VERSION@</string> \
	</dict>   \
	</plist> \
	" >  $(bundle_contents)/Info.plist
endif



if MINGW
nsis_installer: all sdwrap.nsi README
	cat README | unix2dos > README.TXT
	cat ../../NEWS | unix2dos > NEWS.TXT
	cat ../../COPYING | unix2dos > COPYING.TXT
	$(STRIP) sdwrap.exe
	makensis sdwrap.nsi 
endif




