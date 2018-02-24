cmake_minimum_required(VERSION 2.8)

add_executable(mathUnitTest math/test_inverse_factorial.cpp)
target_link_libraries(mathUnitTest ProconMath gtest gtest_main pthread)
