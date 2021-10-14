cmake_minimum_required(VERSION 3.16)

project(Homework1 VERSION 1.0.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pthread")

#add_compile_options("--coverage")

set(LIB_SOURCE_FILES fun.c)
add_library(fun STATIC ${LIB_SOURCE_FILES})
add_executable(prog main.c)
target_link_libraries(prog fun)


enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(fun_test fun_test.cpp)
target_link_libraries(fun_test ${GTEST_LIBRARIES} fun pthread)

