project(PrintArrays)
cmake_minimum_required(VERSION 3.20)


# Set the standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
# If the automatic support using conan-cmake does not work because you don't have a system-wide conan instalation (you
# have installed conan in a virtual environment) then use the two lines below and manually call "conan install .." from
# the build folder.
if(EXISTS ${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
  include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup(TARGETS)
else()
  message(FATAL_ERROR "The file conanbuildinfo.cmake doesn't exist! Run the command below from conan folder
    conan install .. --build=missing -s build_type=Release")
endif()
# xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

# find_package(armadillo REQUIRED)

add_executable(print_arrays src/print_arrays.cpp)

add_executable(print_arrays2 src/print_arrays2.cpp)
target_link_libraries(print_arrays2 CONAN_PKG::armadillo)


add_executable(breakpoint_commands src/breakpoint_commands.cpp)
