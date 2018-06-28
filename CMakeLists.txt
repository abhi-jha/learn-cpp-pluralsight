cmake_minimum_required(VERSION 3.10)
project(learn_cpp_pluralsight)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG  ")
find_package(Threads REQUIRED)
include_directories("${PROJECT_SOURCE_DIR}/")

set(Sources main.cpp sqlite3.c)
set(Headers sqlite3.h)
add_executable(learn_cpp_pluralsight ${Sources} ${Headers})
target_link_libraries(learn_cpp_pluralsight Threads::Threads -ldl)