cmake_minimum_required(VERSION 2.8)
project(OnionWorld)

if(CMAKE_COMPILER_IS_GNUCXX)
#  message("compiler detected as: GNU compiler")
  execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "-dumpversion" OUTPUT_VARIABLE CXX_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
#  message("compiler: ${CMAKE_CXX_COMPILER}")
#  message("version: ${CXX_VERSION}")
  if(${CXX_VERSION} VERSION_GREATER "4.6.99")
    SET(CMAKE_CXX_FLAGS "-std=c++11" )
  else()
    SET(CMAKE_CXX_FLAGS "-std=c++0x" )
  endif()
else()
#  message("compiler detected as: non-GNU compiler")
endif()

set(CMAKE_CPP_FLAGS "-Wall -pedantic" )

set(DATADIR "${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}")

set(Boost_USE_STATIC_LIBS        ON)
find_package( Boost 1.36.0 COMPONENTS regex)
link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )

configure_file ("${PROJECT_SOURCE_DIR}/config.h.in"
                "${PROJECT_BINARY_DIR}/config.h" )

# OpenGL
find_package(OpenGL REQUIRED)
find_package(GLUT)

add_subdirectory(common)
add_subdirectory(render)
add_subdirectory(game)

install(DIRECTORY data DESTINATION ${DATADIR})
