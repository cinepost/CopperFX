file( GLOB SOURCES
	./*.cpp
)

# find python libs
find_package( PythonLibs 2.7 REQUIRED )
include_directories( ${PYTHON_INCLUDE_DIRS} )

# find boost libs
find_package( Boost COMPONENTS python REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} )

SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_USE_STATIC_RUNTIME OFF)

find_package( OpenCL REQUIRED )
include_directories( ${OpenCL_INCLUDE_DIRS} )
link_directories( ${OpenCL_LIBRARY} )

# define wrapper library
add_library( hou SHARED ${SOURCES} )
target_include_directories ( hou PUBLIC ${COPPER_INCLUDE_DIRECTORY} )
target_link_libraries( hou ${Boost_LIBRARIES} ${PYTHON_LIBRARIES} ${OpenCL_LIBRARY} copper_lib )

# don't prepend wrapper library name with lib
set_target_properties( hou PROPERTIES PREFIX "" )
set_target_properties( hou PROPERTIES SUFFIX ".so" )

install(TARGETS hou DESTINATION copper/python2.7libs)