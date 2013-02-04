file(GLOB RENDER_SOURCES "*.cpp")

include_directories(${PROJECT_BINARY_DIR})
include_directories(${OnionWorld_SOURCE_DIR})

add_library(render ${RENDER_SOURCES})
