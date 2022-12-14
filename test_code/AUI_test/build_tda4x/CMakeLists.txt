cmake_minimum_required(VERSION 3.0)  

#项目名
project(auitest)

set(SDK_PATH /home/yardie/Desktop/TDA4X_master)

#指定交叉工具链
set(CMAKE_C_COMPILER ${SDK_PATH}/ti-processor-sdk-rtos-j7-evm-07_03_00_05/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER ${SDK_PATH}/ti-processor-sdk-rtos-j7-evm-07_03_00_05/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin/aarch64-none-linux-gnu-g++)

#设置模块路径为变量
set(TEST_SOURCE_DIR ${SDK_PATH}/AUI)
set(GTEST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../googletest-release-1.12.1)

add_definitions(-D_TDA4X=1)

#所有使用到的头文件路径
include_directories(
    ${GTEST_SOURCE_DIR}/googletest/include
	${GTEST_SOURCE_DIR}/googletest/include/gtest
    ${PROJECT_SOURCE_DIR}/../src/test_src
    ${PROJECT_SOURCE_DIR}/../src/common
    ${TEST_SOURCE_DIR}/ui/shader
    ${TEST_SOURCE_DIR}/ui/aicontrol
    ${TEST_SOURCE_DIR}/ui/comm
    ${TEST_SOURCE_DIR}/ui/datamng
    ${TEST_SOURCE_DIR}/ui/product/adaptor/device
    ${TEST_SOURCE_DIR}/ui/product/adaptor/util
)

#链接库路径
link_directories(${GTEST_SOURCE_DIR}/build_tda4x/lib/)
link_directories(${TEST_SOURCE_DIR}/ui/build/shader)
link_directories(${TEST_SOURCE_DIR}/ui/build/aicontrol)
link_directories(${TEST_SOURCE_DIR}/ui/build/module)
link_directories(${TEST_SOURCE_DIR}/ui/build/app)
link_directories(${TEST_SOURCE_DIR}/ui/build/look)
link_directories(${TEST_SOURCE_DIR}/ui/build/datamng)
link_directories(${TEST_SOURCE_DIR}/ui/build/show)
link_directories(${TEST_SOURCE_DIR}/ui/build)

link_directories(${TEST_SOURCE_DIR}/ui/product/lib/4x)
link_directories(${TEST_SOURCE_DIR}/ui/product/lib/4x/boost)
link_directories(${TEST_SOURCE_DIR}/ui/product/lib/4x/opencv)
link_directories(${SDK_PATH}/ti-processor-sdk-rtos-j7-evm-07_03_00_05/targetfs/opt/img-powervr-sdk/PVRHub/PVRTrace/Recorder)
link_directories(${SDK_PATH}/ti-processor-sdk-rtos-j7-evm-07_03_00_05/targetfs/usr/lib)
link_directories(${SDK_PATH}/ti-processor-sdk-rtos-j7-evm-07_03_00_05/targetfs/lib)



file(GLOB_RECURSE CPP_SRC_LIST_DEVICE_SUB ${TEST_SOURCE_DIR}/ui/product/adaptor/device/*.cpp)
file(GLOB_RECURSE C_SRC_LIST_DEVICE_SUB ${TEST_SOURCE_DIR}/ui/product/adaptor/device/*.c)

set(SOURCE_FILES
    ../src/main.cpp
    ../src/test_src/aui_shader_test.cpp
    ../src/test_src/aui_aicontrol_test.cpp
    ../src/test_src/aui_mcu_test.cpp
    ../src/common/common.cpp
    ${CPP_SRC_LIST_DEVICE_SUB}
    ${C_SRC_LIST_DEVICE_SUB}
)

#生成可执行文件
add_executable(auitest ${SOURCE_FILES})

set(LIB_NAMES
    PVRTrace
    GLESv2
    shader
    aicontrol
    show
    freetype
    png16
    z
    datamng
    look
    getGtc1Counter
)

#链接
target_link_libraries(auitest gtest gtest_main gmock gmock_main pthread ${LIB_NAMES})
