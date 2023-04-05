cmake_minimum_required(VERSION 3.22)
project(Cpp_Study)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(1_基础)
add_subdirectory(2_通讯录管理系统)
add_subdirectory(3_c++核心编程)


add_executable(Cpp_Study main.cpp)
add_executable(letcode lettcode.cpp)




