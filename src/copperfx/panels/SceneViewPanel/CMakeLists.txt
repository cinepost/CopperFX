file( GLOB SOURCES
	./*.cpp
)

# Qt5
find_package( Qt5 COMPONENTS Svg Gui Widgets Core REQUIRED )
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

#include_directories(
#  ${Qt5Widgets_INCLUDES}
#  ${Qt5Core_INCLUDES}
#  ${Qt5Gui_INCLUDES}
#  ${Qt5Svg_INCLUDES}
#)

#include_directories(
#  ${Qt5Core_location} 
#  ${QtWidgets_location}
#  ${QtGui_location}
#  ${QtSvg_location}
#)

# find boost libs
find_package( Boost COMPONENTS log REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} )

# we will use static libs
add_definitions(-DBOOST_LOG_DYN_LINK)

add_library( scene_view STATIC ${SOURCES} ${HEADERS} )

target_link_libraries( 
	scene_view 
	${OpenCL_LIBRARY} 
	dl Boost::log
)
#	Qt5::Core
#	Qt5::Widgets
#	Qt5::Gui
#	Qt5::Svg
#)

qt5_use_modules( scene_view Core Gui Widgets Svg )

install( TARGETS scene_view DESTINATION "lib" )
