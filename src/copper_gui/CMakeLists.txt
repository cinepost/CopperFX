set (SOURCES 
	./copper_gui.cpp)


# find Qt4 libs
find_package( Qt4 REQUIRED )
include( ${QT_USE_FILE} )
add_definitions( ${QT_DEFINITIONS} )

include_directories( ${COPPER_INCLUDE_DIRECTORY} )


add_executable (copper ${SOURCES} ${MOC_SRCS} ${RES_SOURCES})
 
target_link_libraries (copper ${QT_LIBRARIES} copper_lib)

install(TARGETS copper DESTINATION bin)