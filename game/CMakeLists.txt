file(GLOB ONIONWORLD_SOURCES "*.cpp")

include_directories(${OnionWorld_SOURCE_DIR})

add_executable(onionworld ${ONIONWORLD_SOURCES})

target_link_libraries(onionworld common)
target_link_libraries(onionworld render)
target_link_libraries(onionworld ${LIBRARIES})
