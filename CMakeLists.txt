cmake_minimum_required(VERSION 3.20)
project(Guess CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(input STATIC input.cpp)
add_library(secret STATIC secret.cpp)

add_executable(guess main.cpp)

target_link_libraries(guess PRIVATE secret)
target_link_libraries(guess PRIVATE input)

add_executable(check_random check_random.cpp)
target_link_libraries(check_random PRIVATE secret)

