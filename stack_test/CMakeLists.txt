cmake_minimum_required(VERSION 2.8)

project(stack_test)

add_subdirectory(stack)

add_executable(stack_test stack_test.c stack_test.c)

target_link_libraries(stack_test stack)

