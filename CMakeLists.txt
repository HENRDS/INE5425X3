cmake_minimum_required(VERSION 3.14)
project(INE5425X3)

set(CMAKE_CXX_STANDARD 11)




add_executable(INE5425X3 main.cc rng.cc rng.hpp tests.cc tests.hpp)