file( GLOB SOURCES
	./*.cpp 
	./OP/*.cpp
	./UT/*.cpp
	./Geometry/*.cpp
)

include_directories( ${COPPER_INCLUDE_DIRECTORY} )

add_library( copper_lib STATIC ${SOURCES} )
target_link_libraries( copper_lib ${OpenCL_LIBRARY} dl)