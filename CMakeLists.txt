cmake_minimum_required(VERSION 3.29)
project(project_x)
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

set(CMAKE_CXX_STANDARD 20)

add_library(bomb  bomb.cpp bombs_input.cpp)
target_include_directories(bomb PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(tests test.cpp bomb.cpp bombs_input.cpp)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE bomb)