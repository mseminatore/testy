cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(test_framework VERSION 1.0 LANGUAGES C)

# testing
enable_testing()
add_test(NAME example_test COMMAND example_test)

# add the includes
include_directories(${PROJECT_SOURCE_DIR})

# add the library
add_library(testy STATIC test_main.c)

# add the executables
add_executable(example_test example_test.c )
target_link_libraries(example_test PRIVATE testy)
