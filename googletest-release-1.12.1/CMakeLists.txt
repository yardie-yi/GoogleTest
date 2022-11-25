# Note: CMake support is community-based. The maintainers do not use CMake
# internally.

cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_COMPILER "/home/yardie/Desktop/TDA4X_master/ti-processor-sdk-rtos-j7-evm-07_03_00_05/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "/home/yardie/Desktop/TDA4X_master/ti-processor-sdk-rtos-j7-evm-07_03_00_05/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++")

if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

if (POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
endif (POLICY CMP0077)

project(googletest-distribution)
set(GOOGLETEST_VERSION 1.12.1)

if(NOT CYGWIN AND NOT MSYS AND NOT ${CMAKE_SYSTEM_NAME} STREQUAL QNX)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

enable_testing()

include(CMakeDependentOption)
include(GNUInstallDirs)

#Note that googlemock target already builds googletest
option(BUILD_GMOCK "Builds the googlemock subproject" ON)
option(INSTALL_GTEST "Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)" ON)

if(BUILD_GMOCK)
  add_subdirectory( googlemock )
else()
  add_subdirectory( googletest )
endif()
