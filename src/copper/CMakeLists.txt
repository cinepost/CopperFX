file( GLOB SOURCES
	./Util/*.cpp
	./OpParameter/*.cpp
	./Operator/*.cpp
	./Prims/*.cpp
	./OpData/*.cpp
	./Plugin/*.cpp
	./*.cpp
)

# find boost libs
find_package( Boost COMPONENTS log REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} )

# we will use static libs
add_definitions(-DBOOST_LOG_DYN_LINK)

add_library( copper_lib SHARED ${SOURCES} ${HEADERS} )

target_link_libraries( copper_lib ${OpenCL_LIBRARY} dl Boost::log)

if(APPLE)
	if( COPPER_BUILD_LIBS_AS_FRAMEWORKS )
		copper_config_framework( copper_lib )

    # Framework is called 'Copper'
    set_target_properties( copper_lib PROPERTIES OUTPUT_NAME Copper )
    install( TARGETS copper_lib DESTINATION "Frameworks" )
  else()
    install( TARGETS copper_lib DESTINATION "lib" )
  endif()

elseif(UNIX)
	install( TARGETS copper_lib DESTINATION "lib" )
endif()
