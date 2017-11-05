file( GLOB SOURCES
	./*.cpp
	./UT/*.cpp
	./Math/*.cpp
	./Parameters/*.cpp
	./Node/*.cpp
	./Geometry/*.cpp
)

include_directories( ${COPPER_INCLUDE_DIRECTORY} )

add_library( copper_lib STATIC ${SOURCES} )
target_link_libraries( copper_lib ${OpenCL_LIBRARY} dl)