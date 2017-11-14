cmake_minimum_required(VERSION 2.8)

project(Szablony)

add_library(szyfrowanie code.cpp code.h)
add_executable(main main.cpp)
target_link_libraries(main szyfrowanie)