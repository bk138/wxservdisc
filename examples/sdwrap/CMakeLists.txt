
#
# source and targets
#
SET(sdwrap_SRCS
   SdwrapApp.cpp
   SdwrapApp.h
   dfltcfg.h
   gui/FrameMain.cpp
   gui/FrameMain.h
   gui/MyFrameMain.cpp
   gui/MyFrameMain.h
   gui/DialogSettings.cpp
   gui/DialogSettings.h
   gui/MyDialogSettings.cpp
   gui/MyDialogSettings.h
   gui/bitmapFromMem.h
   gui/res/about.png.h
   gui/res/add.png.h
   gui/res/info.png.h
   gui/res/remove.png.h
   gui/res/sdwrap.xpm
   gui/res/icon.icns
)

add_executable(sdwrap ${sdwrap_SRCS})



#
# dependencies
#
include_directories(../../src)


find_package(wxWidgets REQUIRED core base adv)
include(${wxWidgets_USE_FILE})
target_link_libraries(sdwrap wxservdisc ${wxWidgets_LIBRARIES})


#
# installation
#
install(TARGETS sdwrap DESTINATION bin)
install(FILES  sdwrap.desktop DESTINATION share/applications/)
install(FILES  gui/res/sdwrap.xpm DESTINATION share/pixmaps)


