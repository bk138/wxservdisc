!define VERSION "0.3"

Name "wxServDisc ${VERSION}"

OutFile "wxServDisc_${VERSION}-setup.exe"

InstallDir $PROGRAMFILES\wxServDisc

Page license
LicenseData COPYING.TXT

Page directory

Page instfiles

Section ""

  SetOutPath $INSTDIR

  #  dll not built by now
  #  File src\wxServDisc\wxServDisc.dll
  File src\wxServDisc\libwxServDisc.a
  File README.TXT

  writeUninstaller $INSTDIR\wxServDisc-uninstall.exe

  # now the shortcuts
  CreateDirectory "$SMPROGRAMS\wxServDisc"
  createShortCut  "$SMPROGRAMS\wxServDisc\Readme.lnk" "$INSTDIR\README.TXT"
  createShortCut  "$SMPROGRAMS\wxServDisc\Uninstall wxServDisc.lnk" "$INSTDIR\wxServDisc-uninstall.exe"

SectionEnd 

section "Uninstall"
 
  # Always delete uninstaller first
  delete $INSTDIR\wxServDisc-uninstall.exe

  # now delete installed files
  delete $INSTDIR\wxServDisc.dll
  delete $INSTDIR\wxServDisc.a
  delete $INSTDIR\NEWS.TXT
  delete $INSTDIR\README.TXT
  RMDir  $INSTDIR
 
  # delete shortcuts
  delete "$SMPROGRAMS\wxServDisc\Readme.lnk"
  delete "$SMPROGRAMS\wxServDisc\News.lnk"
  delete "$SMPROGRAMS\wxServDisc\Uninstall wxServDisc.lnk"
  RMDir  "$SMPROGRAMS\wxServDisc"
  
sectionEnd

Function un.onInit
    MessageBox MB_YESNO "This will uninstall wxServDisc. Continue?" IDYES NoAbort
      Abort ; causes uninstaller to quit.
    NoAbort:
FunctionEnd
