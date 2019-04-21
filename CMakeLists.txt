cmake_minimum_required( VERSION 3.5 )

set( PROJECT_VERSION_MAJOR 0)
set( PROJECT_VERSION_MINOR 0)
set( PROJECT_VERSION_PATCH 001)

# Basic information about project
project( CopperFX VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH} )

# Add folder where are supportive functions
set( CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake )
set( CMAKE_INCLUDE_CURRENT_DIR ON )

# Set PROJECT_VERSION_PATCH and PROJECT_VERSION_TWEAK to 0 if not present, needed by add_project_meta
#fix_project_version()

# Set additional project information
set( COMPANY "Red Max Soft" )
set( COPYRIGHT "Copyright (c) 2019 Red Max Soft" )
set( IDENTIFIER "com.scalart.redmaxsoft" )

set( CMAKE_INSTALL_PREFIX /opt/cfs${PROJECT_VERSION} )

# Include Qt basic functions
include( QtCommon )

set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE "DEBUG" )
  #SET(CMAKE_BUILD_TYPE "RELEASE")
  #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
  #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
endif()

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

if ( MSVC )
	ADD_DEFINITIONS(/W3)
elseif ( UNIX ) #(CMAKE_COMPILER_IS_GNUCXX)
	ADD_DEFINITIONS(-Wall -fPIC -pedantic)
else ()
	MESSAGE(FATAL_ERROR "CMakeLists.txt has not been tested/written for your compiler.")
endif ()

set ( COPPER_INCLUDE_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src )
include_directories(
    ${COPPER_INCLUDE_ROOT}
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party
)

# Documentation

find_package(Doxygen)
if (DOXYGEN_FOUND)
    # set input and output files
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    # request to configure the file
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

    # note the option ALL which allows to build the docs together with the application
    add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else (DOXYGEN_FOUND)
  message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

# Now libs and executables

# copper libs
add_subdirectory( src/copper ) # main copper library

# copper python modules
add_subdirectory( src/copper_pymodule ) # copper hstyle python module

# copper bins
add_subdirectory( src/copperfx )   # gui application
add_subdirectory( src/copperpy )   # commandline / embedded python interpreter


install(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/cfs 
	DESTINATION ${CMAKE_INSTALL_PREFIX}
	FILES_MATCHING PATTERN "*"
)