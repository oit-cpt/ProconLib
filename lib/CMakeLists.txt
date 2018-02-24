cmake_minimum_required(VERSION 2.8)

file(GLOB MATH_FILES "math/*.cpp")
add_library(ProconMath STATIC ${MATH_FILES})
