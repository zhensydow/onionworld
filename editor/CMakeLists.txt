file(GLOB OWEDITOR_SOURCES "*.cpp")

include_directories(${PROJECT_BINARY_DIR})
include_directories(${OnionWorld_SOURCE_DIR})

include(${QT_USE_FILE})

set(oweditor_MOC_HDRS
  ../gui/glwidget.h
)

qt4_wrap_cpp(oweditor_MOC_SRCS ${oweditor_MOC_HDRS})

add_executable(oweditor ${OWEDITOR_SOURCES} ${oweditor_MOC_SRCS} ../gui/glwidget.cpp )

target_link_libraries(oweditor render common)
target_link_libraries(oweditor ${QT_LIBRARIES})
target_link_libraries(oweditor ${Boost_LIBRARIES})

install(TARGETS oweditor RUNTIME DESTINATION bin)
