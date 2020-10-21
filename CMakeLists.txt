cmake_minimum_required(VERSION 3.5)

project(eigen_swig_test)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

find_package(Eigen3 REQUIRED)


add_library(foo STATIC include/foo.h foo.cpp)

target_include_directories(foo PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
      "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>")

target_link_libraries(foo
  Eigen3::Eigen)

add_subdirectory(bindings)
