cmake_minimum_required(VERSION 3.5.0)
set(CMAKE_CXX_STANDARD 11)
# add_definitions(-std=c++11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(Location VERSION 0.0.0)

include(CTest)
enable_testing()

add_executable(Location_1 lession_1/Initialize_Priors_Function.cpp)
add_executable(Location_2 lession_2/main.cpp lession_2/helpers.hpp)
add_executable(Location_3 lession_3/main.cpp lession_3/helpers.h)
add_executable(Location_Markov code_full_filter/main.cpp code_full_filter/helpers.h)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
