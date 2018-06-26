cmake_minimum_required(VERSION 2.8)

file(GLOB TEST_FILES "*/test_*.cpp")
add_executable(runTest ${TEST_FILES})
target_link_libraries(runTest ProconMath gtest gtest_main pthread)
