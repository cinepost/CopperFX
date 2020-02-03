include( QtCommon )

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
#list(APPEND CMAKE_PREFIX_PATH "/home/max/Qt5.9.1/5.9.1/gcc_64")

if(POLICY CMP0071)
  cmake_policy(SET CMP0071 NEW)
endif()

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTORCC ON)

add_project_meta(META_FILES_TO_INCLUDE)

find_package( Qt5 COMPONENTS Core Svg Gui Widgets REQUIRED )
set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")


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

#qt5_use_modules( copperfx Core Gui Widgets Svg )

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
  scene_view
  node_flow_view
  Boost::log
)
#  Qt5::Core
#  Qt5::Widgets
#  Qt5::Gui
#  Qt5::Svg
#)

if(APPLE)
  install( TARGETS copperfx DESTINATION ${CMAKE_INSTALL_PREFIX} )
elseif(UNIX)
  install( TARGETS copperfx DESTINATION ${CMAKE_INSTALL_PREFIX}/bin )
endif()

# copperfx built ins
add_subdirectory( panels )