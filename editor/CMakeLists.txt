file(GLOB OWEDITOR_SOURCES "*.cpp")

include(${QT_USE_FILE})
message("Libs: ${QT_LIBRARIES}")

add_executable(oweditor ${OWEDITOR_SOURCES})

install(TARGETS oweditor RUNTIME DESTINATION bin)

target_link_libraries(oweditor ${QT_LIBRARIES})
