file( GLOB SOURCES
	./*.cpp
	./UT/*.cpp
	./Parameters/*.cpp
	./OP/*.cpp
	./GEO/*.cpp
)

#include_directories( ${COPPER_INCLUDE_DIRECTORY} )

add_library( copper_lib STATIC ${SOURCES} )
target_link_libraries( copper_lib ${OpenCL_LIBRARY} dl)

#add_custom_command(
#  TARGET copper_lib
#  POST_BUILD
#  COMMAND echo ${CMAKE_INSTALL_PREFIX}
#  COMMAND mkdir ARGS -p ${CMAKE_INSTALL_PREFIX}/lib/python2.7libs
#  COMMAND rsync ARGS -r
#    "${CMAKE_CURRENT_SOURCE_DIR}/../cfs/*"
#    "${CMAKE_INSTALL_PREFIX}/"
#  COMMENT "Copying Bundle Stuff"
#)