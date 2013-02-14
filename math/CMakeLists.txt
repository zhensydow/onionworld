file(GLOB MATH_SOURCES "*.cpp")

include_directories(${OnionWorld_SOURCE_DIR})

add_library(math ${MATH_SOURCES})
