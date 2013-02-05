file(GLOB COMMON_SOURCES "*.cpp")

include_directories(${OnionWorld_SOURCE_DIR})

add_library(tinyxml2 ${COMMON_SOURCES})
