file( GLOB SOURCES
	./*.cpp
)

# find boost libs
find_package( Boost COMPONENTS log REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} )

# we will use static libs
add_definitions(-DBOOST_LOG_DYN_LINK)

add_library( box_geo_op STATIC ${SOURCES} ${HEADERS} )

target_link_libraries( box_geo_op dl Boost::log)

install( TARGETS box_geo_op DESTINATION "lib" )
