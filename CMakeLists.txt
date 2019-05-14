cmake_minimum_required(VERSION 3.13)
project(Test1)

include_directories(/Users/jianchaosun/Downloads/googletest-release-1.8.0/googletest/include/)


set(CMAKE_CXX_STANDARD 11)

link_directories(/Users/jianchaosun/Downloads/googletest-release-1.8.0/mybuild/googlemock/gtest/)

add_executable(Test1 main.cpp BigNumber.h)

target_link_libraries(Test1 gtest gtest_main pthread)