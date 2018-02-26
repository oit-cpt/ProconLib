cmake_minimum_required(VERSION 2.8)

file(GLOB MATH_FILES "Math/*.cpp")
add_library(ProconMath STATIC ${MATH_FILES})
