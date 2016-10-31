cmake_minimum_required(VERSION 3.6)
project(Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Person.cpp Person.h Employee.cpp Employee.cpp Employee.h Programmer.cpp Programmer.h Student.cpp Student.h Account.cpp Account.h Cash.cpp)
add_executable(Project ${SOURCE_FILES})