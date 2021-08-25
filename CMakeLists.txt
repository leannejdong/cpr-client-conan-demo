cmake_minimum_required(VERSION 3.16)

project(myproject CXX)

add_executable(${PROJECT_NAME} main.cpp)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake) # Include Conan-generated file
conan_basic_setup(TARGETS) # Introduce Conan-generated targets
add_compile_options(-std=c++2a -Wall -Wextra)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::cpr)

