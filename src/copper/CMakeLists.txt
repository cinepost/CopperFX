file( GLOB SOURCES
	./*.cpp
	./Util/*.cpp
	./Parameters/*.cpp
	./Operator/*.cpp
	./GEO/*.cpp
	./OpData/*.cpp
	./Plugin/*.cpp
)

# find boost libs
find_package( Boost COMPONENTS log REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} )

# we will use static libs
add_definitions(-DBOOST_LOG_DYN_LINK)

add_library( copper_lib SHARED ${SOURCES} ${HEADERS} )

target_link_libraries( copper_lib ${OpenCL_LIBRARY} dl Boost::log)

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