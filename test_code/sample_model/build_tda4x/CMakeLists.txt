cmake_minimum_required(VERSION 3.0)  

#项目名
project(mytest)

set(SDK_PATH /home/yardie/Desktop/TDA4X_master)

#指定交叉工具链
set(CMAKE_C_COMPILER ${SDK_PATH}/ti-processor-sdk-rtos-j7-evm-07_03_00_05/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER ${SDK_PATH}/ti-processor-sdk-rtos-j7-evm-07_03_00_05/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++)

#设置模块路径为变量
set(TEST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../sample_src_code)
set(GTEST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../googletest-release-1.12.1)

#所有使用到的头文件路径
include_directories(${TEST_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/../include
    ${GTEST_SOURCE_DIR}/googletest/include
	${GTEST_SOURCE_DIR}/googletest/include/gtest
)

#链接库路径
link_directories(${GTEST_SOURCE_DIR}/build_tda4x/lib/)
link_directories(${TEST_SOURCE_DIR})

#生成可执行文件
add_executable(mytest ../main.cpp ../src/mytest.cpp)
#链接
target_link_libraries(mytest testsrctda4x gtest gtest_main gmock gmock_main pthread)




