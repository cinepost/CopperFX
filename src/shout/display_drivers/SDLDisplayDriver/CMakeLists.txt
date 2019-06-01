file( GLOB SOURCES 
	./*.cpp
) 

include_directories (
	${CMAKE_CURRENT_SOURCE_DIR}
)

if (NOT CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
  set (flags_1 "-Wno-overloaded-virtual")
else()
  set (flags_1 "-MP /wd4251")
endif()


# we will use static libs
add_definitions(-DBOOST_LOG_DYN_LINK)

# find boost libs
find_package( Boost COMPONENTS log REQUIRED )
include_directories( ${Boost_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} )

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

if(APPLE)
	include_directories ( /System/Library/Frameworks )
endif()

# find opengl libs 
find_library(OpenGL_LIBRARY OpenGL )

find_package( Threads )

add_library ( sdl_display_lib SHARED ${SOURCES} )

target_link_libraries( sdl_display_lib Boost::log Threads::Threads ${OpenGL_LIBRARY} ${SDL2_LIBRARIES})

set_target_properties( sdl_display_lib PROPERTIES
	CXX_STANDARD 11
	CXX_STANDARD_REQUIRED ON
	CXX_EXTENSIONS ON
	PREFIX "d_"
	SUFFIX ".so"
	OUTPUT_NAME "sdldisplay"
)


if(APPLE)
	file(GLOB dist_lib_files "${PROJECT_SOURCE_DIR}/dist/macos/*")
	install( FILES
		${dist_lib_files} DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	)
endif()


install(TARGETS sdl_display_lib
	RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
	LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
	ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)