cmake_minimum_required(VERSION 3.16)
project(cpplearn)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpplearn main.cpp)
add_executable(ObjectInit Unit4/ObjectInit.cpp Unit4/Person.hpp)
add_executable(ObjectCopy Unit4/ObjectCopy.cpp Unit4/Person.hpp)
add_executable(ObjectArrayAndPoint Unit4/ObjectArrayAndPoint.cpp Unit4/Person.hpp)
add_executable(ReturnObject Unit4/ReturnObject.cpp Unit4/Person.hpp)
add_executable(ClassInit Unit4/ClassInit.cpp Unit4/Person.hpp)