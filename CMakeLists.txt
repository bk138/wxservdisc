cmake_minimum_required(VERSION 3.0)

add_subdirectory(src)
add_subdirectory(examples)


########### install files ###############

install(FILES  README.md 	AUTHORS 	NEWS DESTINATION doc/wxservdisc)


