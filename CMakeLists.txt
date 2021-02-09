cmake_minimum_required(VERSION 3.17)
project(competitive_programming)

set(CMAKE_CXX_STANDARD 14)
set(ACTIVE_PATH ./sit_star_2021/practice_round)
set(ACTIVE_PROBLEM problemF_greedy)

add_subdirectory(googletest)
enable_testing()
#add_subdirectory(${ACTIVE_PATH}/tests)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(competitive_programming ${ACTIVE_PATH}/src/${ACTIVE_PROBLEM}.cpp)
#add_executable(competitive_programming_test ${ACTIVE_PATH}/tests/${ACTIVE_PROBLEM}_test.cpp)

#target_link_libraries(competitive_programming_test gtest gtest_main)
#add_test( competitive_programming_test competitive_programming_test )
