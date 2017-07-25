project ( CopperFX )
CMAKE_MINIMUM_REQUIRED( VERSION 3.5 )

set(PROJECT_BUILD_DIR ${CMAKE_HOME_DIRECTORY}/build) 
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BUILD_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BUILD_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BUILD_DIR}/bin)

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE "DEBUG")
  #SET(CMAKE_BUILD_TYPE "RELEASE")
  #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
  #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
ENDIF()

set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_INSTALL_PREFIX "./bin" )

if (MSVC)
	ADD_DEFINITIONS(/W3)
elseif (CMAKE_COMPILER_IS_GNUCXX)
	ADD_DEFINITIONS(-Wall -fPIC -pedantic)
else ()
	MESSAGE(FATAL_ERROR "CMakeLists.txt has not been tested/written for your compiler.")
endif ()

#IF(CMAKE_COMPILER_IS_GNUCXX)
#  ADD_DEFINITIONS("-Wall -fPIC")
#ELSE()
#  MESSAGE(FATAL_ERROR "CMakeLists.txt has not been tested/written for your compiler.")
#ENDIF()

include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

add_subdirectory( copper )
add_subdirectory( copper_gui )
add_subdirectory( copper_pymodule )