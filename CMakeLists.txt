cmake_minimum_required( VERSION 3.5 )

set( CMAKE_INSTALL_PREFIX /opt/cfs0.0.001 )


# Add folder where are supportive functions
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Include Qt basic functions
include(QtCommon)

# Basic information about project
project( CopperFX VERSION 0.0 )

# Set PROJECT_VERSION_PATCH and PROJECT_VERSION_TWEAK to 0 if not present, needed by add_project_meta
fix_project_version()

# Set additional project information
set(COMPANY "Red Soft")
set(COPYRIGHT "Copyright (c) 2019 Max. All rights reserved.")
set(IDENTIFIER "com.example.Example")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
  #SET(CMAKE_BUILD_TYPE "RELEASE")
  #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
  #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
ENDIF()

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

if (MSVC)
	ADD_DEFINITIONS(/W3)
elseif (UNIX) #(CMAKE_COMPILER_IS_GNUCXX)
	ADD_DEFINITIONS(-Wall -fPIC -pedantic)
else ()
	MESSAGE(FATAL_ERROR "CMakeLists.txt has not been tested/written for your compiler.")
endif ()

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/include/copper )

add_subdirectory( src/copper_lib )
add_subdirectory( src/copper_gui )
add_subdirectory( src/copper_pymodule )

#install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/cfs/* DESTINATION ${CMAKE_INSTALL_PREFIX}/)