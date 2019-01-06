set(SOURCE_FILES
    ./copper_gui.cpp
    ./GUI_MainWindow.cpp
)

set(HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/../../include/copper/GUI/GUI_MainWindow.h
)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../include/copper/GUI )

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTORCC ON)

add_project_meta(META_FILES_TO_INCLUDE)

find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets CONFIG REQUIRED )

get_target_property(QtCore_location Qt5::Core LOCATION)
get_target_property(QtWidgets_location Qt5::Widgets LOCATION)

include_directories(${QtCore_location} ${QtWidgets_location})

if(APPLE)
  set( APP_ICON_NAME copperfx_icon.icns )
  set( APP_ICON_PATH ./media/icons/${APP_ICON_NAME} )
  set( MACOSX_BUNDLE_ICON_FILE ${APP_ICON_NAME} )
  set_source_files_properties( ${APP_ICON_PATH} PROPERTIES MACOSX_PACKAGE_LOCATION Resources )
  set( MACOSX_BUNDLE_BUNDLE_NAME “CopperFX”)
endif()

add_executable(
	copperfx
	${OS_BUNDLE} # Expands to WIN32 or MACOS_BUNDLE depending on OS
    ${APP_ICON_PATH} 
    ${SOURCE_FILES}
    ${HEADER_FILES}
    #${META_FILES_TO_INCLUDE}
)

qt5_use_modules( copperfx Core Gui Widgets)

target_link_libraries ( 
	copperfx
	copper_lib 
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
)


if(APPLE)
  install( TARGETS copperfx DESTINATION /Applications/RedSoft )
elseif(UNIX)
  install( TARGETS copperfx DESTINATION ${CMAKE_INSTALL_PREFIX}/bin )
endif()