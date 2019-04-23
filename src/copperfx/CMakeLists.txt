file( GLOB CPP_FILES 
  ./Ui/*.cpp
  ./*.cpp
) 

set( SOURCE_FILES 
  ${CPP_FILES} ${H_FILES}
)

# Find includes in corresponding build directories
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Boost

find_package( Boost COMPONENTS log REQUIRED )
include_directories( 
  ${Boost_INCLUDE_DIRS} 
)

# we will use static libs
add_definitions(-DBOOST_LOG_DYN_LINK)

# Qt5
list(APPEND CMAKE_PREFIX_PATH "/home/max/Qt5.9.1/5.9.1/gcc_64")

if(POLICY CMP0071)
  cmake_policy(SET CMP0071 NEW)
endif()

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTORCC ON)

add_project_meta(META_FILES_TO_INCLUDE)

find_package( Qt5Core REQUIRED )
find_package( Qt5Svg REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Widgets CONFIG REQUIRED )

get_target_property(QtCore_location Qt5::Core LOCATION)
get_target_property(QtWidgets_location Qt5::Widgets LOCATION)

include_directories(
  ${Qt5Core_location} 
  ${QtWidgets_location}
  ${QtGui_location}
  ${QtSvg_location}
)

include_directories(
  ${Qt5Widgets_INCLUDES}
  ${Qt5Core_INCLUDES}
  ${Qt5Gui_INCLUDES}
  ${Qt5Svg_INCLUDES}
)

if(APPLE)
  set( APP_ICON_NAME copperfx_icon.icns )
  set( APP_ICON_PATH ./media/icons/${APP_ICON_NAME} )
  set( MACOSX_BUNDLE_ICON_FILE ${APP_ICON_NAME} )
  set_source_files_properties( ${APP_ICON_PATH} PROPERTIES MACOSX_PACKAGE_LOCATION Resources )
  set( MACOSX_BUNDLE_BUNDLE_NAME “Copper FX ${PROJECT_VERSION}”)
endif()

qt5_add_resources( RCC_SOURCES ./resources.qrc )

add_executable(
  copperfx
  ${OS_BUNDLE} # Expands to WIN32 or MACOS_BUNDLE depending on OS
  ${APP_ICON_PATH} 
  ${SOURCE_FILES}
  ${RCC_SOURCES}
)

#target_include_directories( copperfx PRIVATE
#   ${PROJECT_ROOT}/include
#)

qt5_use_modules( copperfx Core Gui Widgets Svg )

if(APPLE)
  set_target_properties(
      copperfx
      PROPERTIES
      INSTALL_NAME_DIR "@rpath/CopperFX.framework/copper"
      INSTALL_RPATH "@executable_path/../../Frameworks;@loader_path/Frameworks"
  )
endif()

target_link_libraries ( 
  copperfx
  copper_lib
  Boost::log
  Qt5::Core
  Qt5::Widgets
  Qt5::Gui
  Qt5::Svg
)

if(APPLE)
  install( TARGETS copperfx DESTINATION ${CMAKE_INSTALL_PREFIX} )
elseif(UNIX)
  install( TARGETS copperfx DESTINATION ${CMAKE_INSTALL_PREFIX}/bin )
endif()