cmake_minimum_required(VERSION 3.16)
project(cpplearn)

set(CMAKE_CXX_STANDARD 17)

add_executable(shared_prt shared_prt.cpp)
add_executable(l_r_value x_value.cpp)
add_executable(r_ref_l_ref r_ref_l_ref.cpp)