set (SOURCES 
	./shout_cmd.cpp
)

# find boost libs
find_package( Boost COMPONENTS program_options log REQUIRED )
include_directories( 
	${Boost_INCLUDE_DIRS} 
	${PROJECT_SOURCE_DIR}/src
	${PROJECT_SOURCE_DIR}/src/shout_lib
)

# we will use static libs
add_definitions(-DBOOST_LOG_DYN_LINK)

add_executable ( shout_cmd ${SOURCES} )
set_target_properties( shout_cmd PROPERTIES OUTPUT_NAME "shout" )
 
target_link_libraries( shout_cmd Boost::log Boost::program_options shout_lib )

install(TARGETS shout_cmd DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)