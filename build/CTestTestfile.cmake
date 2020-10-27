# CMake generated Testfile for 
# Source directory: C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem
# Build directory: C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(KnapsackTest "C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/build/Debug/KnapsackTest.exe")
  set_tests_properties(KnapsackTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/CMakeLists.txt;24;add_test;C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(KnapsackTest "C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/build/Release/KnapsackTest.exe")
  set_tests_properties(KnapsackTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/CMakeLists.txt;24;add_test;C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(KnapsackTest "C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/build/MinSizeRel/KnapsackTest.exe")
  set_tests_properties(KnapsackTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/CMakeLists.txt;24;add_test;C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(KnapsackTest "C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/build/RelWithDebInfo/KnapsackTest.exe")
  set_tests_properties(KnapsackTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/CMakeLists.txt;24;add_test;C:/Users/Adrian/Desktop/-AAL-Discrete-Knapsack-Problem/CMakeLists.txt;0;")
else()
  add_test(KnapsackTest NOT_AVAILABLE)
endif()
