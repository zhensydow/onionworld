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

set(CMAKE_CPP_FLAGS "-Wall" )

set(DATADIR "${PROJECT_BINARY_DIR}")

configure_file ("${PROJECT_SOURCE_DIR}/config.h.in"
                "${PROJECT_BINARY_DIR}/config.h" )

# OpenGL
find_package(OpenGL REQUIRED)
find_package(GLUT)

set(LIBRARIES ${LIBRARIES} ${OPENGL_LIBRARY})
set(LIBRARIES ${LIBRARIES} ${GLUT_LIBRARY})

add_subdirectory(common)
add_subdirectory(game)
