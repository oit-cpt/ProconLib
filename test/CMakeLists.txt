cmake_minimum_required(VERSION 2.8)

file(GLOB MATH_TEST_FILES "math/test_*.cpp")
add_executable(mathTest ${MATH_TEST_FILES})
target_link_libraries(mathTest ProconMath gtest gtest_main pthread)
