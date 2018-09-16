file(GLOB SOURCES 
	./*.cpp
)

set( CMAKE_PREFIX_PATH "/Users/max/Qt/5.11.1/clang_64" )

# find Qt5 libs
find_package( Qt5Core REQUIRED )
find_package( Qt5Gui REQUIRED )
find_package( Qt5Widgets REQUIRED )

include_directories( ${COPPER_INCLUDE_DIRECTORY} ${QT_INCLUDES} )

set(CMAKE_CXX_FLAGS "${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

add_executable ( copper ${SOURCES} )

target_link_libraries ( copper ${QT_LIBRARIES} Qt5::Core Qt5::Gui Qt5::Widgets copper_lib )

install( TARGETS copper DESTINATION ${CMAKE_INSTALL_PREFIX}/bin )