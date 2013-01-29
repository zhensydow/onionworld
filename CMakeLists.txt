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

SET(CMAKE_CPP_FLAGS "-Wall" )

# OpenGL
find_package(OpenGL REQUIRED)
find_package(GLUT)

SET(LIBRARIES ${LIBRARIES} ${OPENGL_LIBRARY})
SET(LIBRARIES ${LIBRARIES} ${GLUT_LIBRARY})

add_executable(onionworld main.cpp fileutils.cpp shaders.cpp)

TARGET_LINK_LIBRARIES(onionworld ${LIBRARIES})
