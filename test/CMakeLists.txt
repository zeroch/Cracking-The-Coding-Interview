set(test_EXECUTABLE module_test)


include_directories(
  ${gtest_SOURCE_DIR}/include
)

add_executable(${test_EXECUTABLE} node_test.cpp)

target_link_libraries(${test_EXECUTABLE} gtest gtest_main pthread)