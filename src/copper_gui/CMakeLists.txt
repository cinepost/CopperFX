set(SOURCE_FILES
    ./copper_gui.cpp
    ./GUI_MainWindow.cpp
)

set(HEADER_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/../../include/copper/GUI/GUI_MainWindow.h
)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../../include/copper/GUI )

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_project_meta(META_FILES_TO_INCLUDE)

find_package( Qt5Widgets CONFIG REQUIRED )

add_executable(
	copper 
	${OS_BUNDLE} # Expands to WIN32 or MACOS_BUNDLE depending on OS
    ${SOURCE_FILES}
    ${HEADER_FILES}
    #${META_FILES_TO_INCLUDE}
)
qt5_use_modules( copper Widgets)

target_link_libraries ( copper copper_lib )

install( TARGETS copper DESTINATION ${CMAKE_INSTALL_PREFIX}/bin )