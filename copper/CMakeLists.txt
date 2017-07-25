file( GLOB SOURCES src/*.cpp )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include )

add_library( copper_lib STATIC ${SOURCES} )
#target_include_directories( copper PUBLIC "${CMAKE_CURRENT_LIST_DIR}/include" )
target_link_libraries( copper_lib ${OpenCL_LIBRARY} dl)