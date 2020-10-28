cmake_minimum_required(VERSION 3.0)

project(aal-discrete-knapsack-problem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

set(SOURCE_FILES
    src/Knapsack.cpp
)

include_directories(
    src
    thirdparty/catch2
)

add_executable(main src/main.cpp ${SOURCE_FILES})

enable_testing()

macro(add_unit_test testname)
    add_executable(${testname} test/${testname}.cpp ${SOURCE_FILES})
    add_test(NAME ${testname} COMMAND ${testname})
endmacro(add_unit_test)

add_unit_test(KnapsackTest)
add_unit_test(ItemTest)
