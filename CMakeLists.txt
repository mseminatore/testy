cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(example_test VERSION 1.0 LANGUAGES C)

# testing
enable_testing()
add_test(NAME example_test COMMAND example_test)

# add the includes
include_directories(${PROJECT_SOURCE_DIR})

# add the executables
add_executable(example_test example_test.c test_main.c)
