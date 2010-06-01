## Process this file with automake to produce Makefile.in


SUBDIRS = \
	src


wxservdiscdocdir = ${datadir}/doc/wxservdisc
wxservdiscdoc_DATA = \
	README\
	AUTHORS\
	ChangeLog\
	NEWS

EXTRA_DIST = $(wxservdiscdoc_DATA)


if DARWIN
bundle_contents = wxServDisc.framework
framework: src/wxServDisc/.libs/libwxservdisc.0.dylib.dSYM src/wxServDisc/.libs/libwxservdisc.a
	mkdir -p $(bundle_contents)/Versions/@PACKAGE_VERSION@
	ln -fs @PACKAGE_VERSION@ $(bundle_contents)/Versions/Current
	cp src/wxServDisc/.libs/libwxservdisc.a $(bundle_contents)/Versions/Current/wxServDisc
	ln -fs Versions/Current/wxServDisc  $(bundle_contents)/wxServDisc
	mkdir -p  $(bundle_contents)/Versions/Current/Libraries
	ln -fs Versions/Current/Libraries $(bundle_contents)/Libraries
	cp -a src/wxServDisc/.libs/libwxservdisc.0.dylib.dSYM  $(bundle_contents)/Libraries/
	mkdir  $(bundle_contents)/Versions/Current/Resources
	ln -fs Versions/Current/Resources $(bundle_contents)/Resources
	mkdir -p  $(bundle_contents)/Versions/Current/Headers
	ln -fs Versions/Current/Headers  $(bundle_contents)/Headers
	cp src/wxServDisc/wxServDisc.h  $(bundle_contents)/Versions/Current/Headers/
	mkdir -p  $(bundle_contents)/Versions/Current/Documentation
	ln -fs Versions/Current/Documentation  $(bundle_contents)/Documentation
	cp README  $(bundle_contents)/Documentation/
	cp NEWS    $(bundle_contents)/Documentation/
	cp COPYING $(bundle_contents)/Documentation/
	cp AUTHORS $(bundle_contents)/Documentation/
	echo \
	"<?xml version="1.0" encoding="UTF-8"?>\
	<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd"\
	<plist version="1.0">\
	<dict>\
	<key>CFBundleGetInfoString</key>\
	<string>wxServDisc Framework @PACKAGE_VERSION@, © Christian Beier (dontmind@freeshell.org), 2008-2010 </string>\
	<key>CFBundleName</key>  \
	<string>wxServDisc</string> \
	<key>CFBundlePackageType</key> \
	<string>FMWK</string>          \
	<key>CFBundleShortVersionString</key> \
	<string>@PACKAGE_VERSION@</string> \
	<key>CFBundleVersion</key> \
	<string>@PACKAGE_VERSION@</string> \
	</dict>   \
	</plist> \
	" > $(bundle_contents)/Versions/Current/Resources/Info.plist
endif


if MINGW
nsis_installer: all wxServDisc.nsi README NEWS COPYING
	cat README | unix2dos > README.TXT
	cat NEWS | unix2dos > NEWS.TXT
	cat COPYING | unix2dos > COPYING.TXT
	makensis wxServDisc.nsi 
endif

