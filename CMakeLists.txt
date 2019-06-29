cmake_minimum_required( VERSION 3.5 )

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

set( PROJECT_VERSION_MAJOR 0 )
set( PROJECT_VERSION_MINOR 0 )
set( PROJECT_VERSION_PATCH 001 )

# Basic information about project
set( PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH} )
project( CopperFX VERSION ${PROJECT_VERSION} )

# Add folder where are supportive functions
set( CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake )
set( CMAKE_INCLUDE_CURRENT_DIR ON )

# Set PROJECT_VERSION_PATCH and PROJECT_VERSION_TWEAK to 0 if not present, needed by add_project_meta
#fix_project_version()

# Set additional project information
set( COMPANY "Red Max Soft" )
set( COPYRIGHT "Copyright (c) 2019 Red Soft" )
set( IDENTIFIER "com.redsoft" )


if( APPLE )
  if(POLICY CMP0068)
    cmake_policy(SET CMP0068 NEW)  # CMake 3.9+: `RPATH` settings on macOS do not affect `install_name`.
  endif()
endif()

if(APPLE)
  set(CMAKE_MACOSX_RPATH 1)
  set( CMAKE_INSTALL_PREFIX "/Applications/Copper/Copper${PROJECT_VERSION}" )
elseif(UNIX)
  set( CMAKE_INSTALL_PREFIX "/opt/cfs${PROJECT_VERSION}" )
endif()

# Include Qt basic functions
include( QtCommon )

# Include config targets
include ( CopperConfigTargets )

# Specify build paths
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
if (WIN32 OR APPLE)
  if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    # We don't want to install in default system location, install is really for the SDK, so call it that
    set(CMAKE_INSTALL_PREFIX "${PROJECT_BINARY_DIR}/sdk" CACHE PATH "COPPER install prefix" FORCE )
  endif (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
endif(WIN32 OR APPLE)

if( NOT CMAKE_BUILD_TYPE )
  set( CMAKE_BUILD_TYPE "DEBUG" )
  #SET(CMAKE_BUILD_TYPE "RELEASE")
  #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
  #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
endif()

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
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/enum-flags/include
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

set( COPPER_BUILD_LIBS_AS_FRAMEWORKS true )

# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${PROJECT_SOURCE_DIR}/third_party/antlr-4.7.1-complete.jar)

# Now setup targets

# thirt party libs
add_subdirectory("third_party/antlr4/runtime/Cpp")

# copper libs
add_subdirectory( src/copper ) # main copper library

# copper python modules
#add_subdirectory( src/copper_pymodules ) # copper python modules

# copper apps
add_subdirectory( src/copperfx )   # gui application
#add_subdirectory( src/copperpy )   # commandline / embedded python interpreter
#add_subdirectory( src/shout ) # renderer

install(
	DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/cfs 
	DESTINATION ${CMAKE_INSTALL_PREFIX}
	FILES_MATCHING PATTERN "*"
)