file( GLOB SOURCES
	./HOU/*.cpp
	./hou_module.cpp
)

# find python libs
find_package( PythonLibs 2.7 REQUIRED )
include_directories( ${PYTHON_INCLUDE_DIRS} )

# find boost libs
if(APPLE)
 find_package( Boost COMPONENTS python27 REQUIRED )
else()
 find_package( Boost COMPONENTS python-py27 REQUIRED )
endif()

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
if (APPLE)
    set_target_properties( hou PROPERTIES SUFFIX ".so" )
endif (APPLE)

install(TARGETS hou DESTINATION lib/python2.7libs)
