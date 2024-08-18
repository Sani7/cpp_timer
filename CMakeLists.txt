cmake_minimum_required(VERSION 3.25)

project(Timer LANGUAGES CXX)

add_library(Timer)

target_compile_options(Timer PRIVATE $<$<CONFIG:Debug>:
    -Wall -Wextra -pedantic-errors -Wconversion -Wsign-conversion
    >)

target_sources(Timer
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/timer.cpp
    
)

target_include_directories(Timer
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)