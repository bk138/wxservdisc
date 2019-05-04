cmake_minimum_required(VERSION 3.0)

option(WXSERVDISC_INSTALL "Generate installation target" ON)

add_subdirectory(src)
add_subdirectory(examples)


########### install files ###############

if(WXSERVDISC_INSTALL)
    install(FILES  README.md 	AUTHORS 	NEWS DESTINATION doc/wxservdisc)
endif()

