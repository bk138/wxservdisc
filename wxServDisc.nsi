!define VERSION "0.3"

Name "wxServDisc ${VERSION}"

OutFile "wxServDisc_${VERSION}-setup.exe"

InstallDir $PROGRAMFILES\wxServDisc

Page license
LicenseData COPYING

Page directory

Page instfiles

Section ""

  SetOutPath $INSTDIR

  #  dll not built by now
  #  File src\wxServDisc\wxServDisc.dll
  File build\src\Release\wxServDisc.lib
  File README.md

  writeUninstaller $INSTDIR\wxServDisc-uninstall.exe

  # now the shortcuts
  CreateDirectory "$SMPROGRAMS\wxServDisc"
  createShortCut  "$SMPROGRAMS\wxServDisc\Readme.lnk" "$INSTDIR\README.md"
  createShortCut  "$SMPROGRAMS\wxServDisc\Uninstall wxServDisc.lnk" "$INSTDIR\wxServDisc-uninstall.exe"

SectionEnd 

section "Uninstall"
 
  # Always delete uninstaller first
  delete $INSTDIR\wxServDisc-uninstall.exe

  # now delete installed files
  delete $INSTDIR\wxServDisc.lib
  delete $INSTDIR\README.md
  RMDir  $INSTDIR
 
  # delete shortcuts
  delete "$SMPROGRAMS\wxServDisc\Readme.lnk"
  delete "$SMPROGRAMS\wxServDisc\Uninstall wxServDisc.lnk"
  RMDir  "$SMPROGRAMS\wxServDisc"
  
sectionEnd

Function un.onInit
    MessageBox MB_YESNO "This will uninstall wxServDisc. Continue?" IDYES NoAbort
      Abort ; causes uninstaller to quit.
    NoAbort:
FunctionEnd
