cmake_minimum_required(VERSION 3.0)  

#项目名
project(auitest)

set(SDK_PATH /home/yardie/Desktop/TDA4X_master)

#指定交叉工具链
set(CMAKE_CXX_STANDARD 11)

#设置模块路径为变量
set(TEST_SOURCE_DIR ${SDK_PATH}/AUI)
set(GTEST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../googletest-release-1.12.1)

#所有使用到的头文件路径
include_directories(
    ${GTEST_SOURCE_DIR}/googletest/include
	${GTEST_SOURCE_DIR}/googletest/include/gtest
    ${PROJECT_SOURCE_DIR}/../include
    ${TEST_SOURCE_DIR}/ui/shader
    ${TEST_SOURCE_DIR}/ui/comm
)

#链接库路径
link_directories(${GTEST_SOURCE_DIR}/build_pc/lib/)
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
link_directories(${TEST_SOURCE_DIR}/lib/Linux_x86_64)



#生成可执行文件
add_executable(auitest ../main.cpp ../src/aui_test.cpp)
#链接
target_link_libraries(auitest gtest gtest_main gmock gmock_main pthread GLESv2 shader)
