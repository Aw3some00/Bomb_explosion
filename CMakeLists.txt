cmake_minimum_required(VERSION 3.29)
project(project_x)

set(CMAKE_CXX_STANDARD 20)

add_executable(tests test.cpp bomb.cpp)
add_executable(main main.cpp bomb.cpp)
