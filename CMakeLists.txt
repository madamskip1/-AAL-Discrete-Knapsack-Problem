cmake_minimum_required(VERSION 3.0)

project(aal-discrete-knapsack-problem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES
    src/Knapsack.cpp
    src/RunMode.cpp
    src/FileStreamRunMode.cpp
)

include_directories(
    src
    thirdparty/catch2
)

add_executable(main src/main.cpp ${SOURCE_FILES})

enable_testing()

add_executable(KnapsackTest test/KnapsackTest.cpp ${SOURCE_FILES})
add_test(NAME KnapsackTest COMMAND KnapsackTest)
