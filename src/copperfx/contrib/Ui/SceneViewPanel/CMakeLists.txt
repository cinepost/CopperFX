file( GLOB SOURCES
	./*.cpp
)

set ( LIBNAME scene_view )

# Qt5
find_package( Qt5Core REQUIRED )
find_package( Qt5Svg REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Widgets CONFIG REQUIRED )

include_directories(
  ${Qt5Widgets_INCLUDES}
  ${Qt5Core_INCLUDES}
  ${Qt5Gui_INCLUDES}
  ${Qt5Svg_INCLUDES}
)

include_directories(
  ${Qt5Core_location} 
  ${QtWidgets_location}
  ${QtGui_location}
  ${QtSvg_location}
)

qt5_use_modules( ${LIBNAME} Core Gui Widgets Svg )

# find boost libs
find_package( Boost COMPONENTS log REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} )

# we will use static libs
add_definitions(-DBOOST_LOG_DYN_LINK)

add_library( ${LIBNAME} SHARED ${SOURCES} ${HEADERS} )

target_link_libraries( ${LIBNAME} ${OpenCL_LIBRARY} dl Boost::log)

install( TARGETS ${LIBNAME} DESTINATION "lib" )
