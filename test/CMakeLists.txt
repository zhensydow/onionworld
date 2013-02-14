file(GLOB TEST_FILES "test*.cpp")

include_directories(${PROJECT_BINARY_DIR})
include_directories(${OnionWorld_SOURCE_DIR})

foreach(testFile ${TEST_FILES})
  get_filename_component(testName ${testFile} NAME_WE)
  add_executable(${testName} ${testFile})
  target_link_libraries(${testName} render common math tinyxml2)
  target_link_libraries(${testName} ${Boost_LIBRARIES})
endforeach()
