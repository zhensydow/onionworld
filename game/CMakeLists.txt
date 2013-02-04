file(GLOB ONIONWORLD_SOURCES "*.cpp")

include_directories(${PROJECT_BINARY_DIR})
include_directories(${OnionWorld_SOURCE_DIR})

include(${QT_USE_FILE})

set(oneworld_MOC_HDRS
  glwidget.h
)

qt4_wrap_cpp(oneworld_MOC_SRCS ${oneworld_MOC_HDRS})

add_executable(onionworld ${ONIONWORLD_SOURCES} ${oneworld_MOC_SRCS})

target_link_libraries(onionworld render common)
target_link_libraries(onionworld ${LIBRARIES})
target_link_libraries(onionworld ${QT_LIBRARIES})
target_link_libraries(onionworld ${Boost_LIBRARIES})

install(TARGETS onionworld RUNTIME DESTINATION bin)
