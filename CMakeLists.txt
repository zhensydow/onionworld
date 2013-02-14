cmake_minimum_required(VERSION 2.8)
project(OnionWorld)
set(OnionWorld_VERSION_MAJOR 0)
set(OnionWorld_VERSION_MINOR 1)

set(BUILD_SHARED_LIBS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

if(CMAKE_COMPILER_IS_GNUCXX)
  execute_process(COMMAND "${CMAKE_CXX_COMPILER}" "-dumpversion" OUTPUT_VARIABLE CXX_VERSION OUTPUT_STRIP_TRAILING_WHITESPACE)
#  message("compiler: ${CMAKE_CXX_COMPILER}")
#  message("version: ${CXX_VERSION}")
  if(${CXX_VERSION} VERSION_GREATER "4.6.99")
    set(CMAKE_CXX_FLAGS "-Wall -std=c++11" )
    set(CMAKE_CXX_FLAGS_DEBUG "-pedantic -g -O0 -DDEBUG" )
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DRELEASE" )
  else()
    set(CMAKE_CXX_FLAGS "-Wall -std=c++0x" )
    set(CMAKE_CXX_FLAGS_DEBUG "-pedantic -g -O0 -DDEBUG" )
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DRELEASE" )
  endif()
else()
#  message("compiler detected as: non-GNU compiler")
endif()

#set(CMAKE_VERBOSE_MAKEFILE on)

set(DATADIR "${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}")

set(Boost_USE_STATIC_LIBS        ON)
find_package( Boost 1.36.0 COMPONENTS regex)
link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )

configure_file ("${PROJECT_SOURCE_DIR}/config.h.in"
                "${PROJECT_BINARY_DIR}/config.h" )

# OpenGL
find_package(Qt4 REQUIRED)
set(QT_USE_QTOPENGL TRUE)

add_subdirectory(common)
add_subdirectory(math)
add_subdirectory(render)
add_subdirectory(tinyxml2)
add_subdirectory(game)
add_subdirectory(editor)
add_subdirectory(test)

# Data files
file(GLOB DATA_DIRS "data/*")
install(DIRECTORY ${DATA_DIRS} DESTINATION ${DATADIR})

# documentation
find_package(Doxygen)
if(DOXYGEN_FOUND)
  configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in" 
    "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile" @ONLY)
  add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMENT "Generating API documentation with Doxygen" VERBATIM
    )
endif()
