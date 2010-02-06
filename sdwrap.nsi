!define VERSION "0.2"

Name "SDWrap ${VERSION}"

OutFile "SDWrap_${VERSION}-setup.exe"

InstallDir $PROGRAMFILES\SDWrap

Page license
LicenseData COPYING.TXT

Page directory

Page instfiles

Section ""

  SetOutPath $INSTDIR

  File src\SDWrap.exe
  File src\mingwm10.dll
  File NEWS.TXT	
  File README.TXT

  writeUninstaller $INSTDIR\SDWrap-uninstall.exe

  # now the shortcuts
  CreateDirectory "$SMPROGRAMS\SDWrap"
  createShortCut  "$SMPROGRAMS\SDWrap\SDWrap.lnk" "$INSTDIR\SDWrap.exe"
  createShortCut  "$SMPROGRAMS\SDWrap\Readme.lnk" "$INSTDIR\README.TXT"
  createShortCut  "$SMPROGRAMS\SDWrap\News.lnk" "$INSTDIR\NEWS.TXT"
  createShortCut  "$SMPROGRAMS\SDWrap\Uninstall SDWrap.lnk" "$INSTDIR\SDWrap-uninstall.exe"

SectionEnd 

section "Uninstall"
 
  # Always delete uninstaller first
  delete $INSTDIR\SDWrap-uninstall.exe

  # now delete installed files
  delete $INSTDIR\SDWrap.exe
  delete $INSTDIR\mingwm10.dll
  delete $INSTDIR\NEWS.TXT
  delete $INSTDIR\README.TXT
  RMDir  $INSTDIR
 
  # delete shortcuts
  delete "$SMPROGRAMS\SDWrap\SDWrap.lnk"
  delete "$SMPROGRAMS\SDWrap\Readme.lnk"
  delete "$SMPROGRAMS\SDWrap\News.lnk"
  delete "$SMPROGRAMS\SDWrap\Uninstall SDWrap.lnk"
  RMDir  "$SMPROGRAMS\SDWrap"
  
sectionEnd

Function un.onInit
    MessageBox MB_YESNO "This will uninstall SDWrap. Continue?" IDYES NoAbort
      Abort ; causes uninstaller to quit.
    NoAbort:
  FunctionEnd
