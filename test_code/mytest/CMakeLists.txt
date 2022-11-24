cmake_minimum_required(VERSION 3.0)  

#项目名
project(mytest)

#指定C++版本为C++11
set(CMAKE_CXX_STANDARD 11)

#设置模块路径为变量
set(TEST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../src_code)
set(GTEST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../googletest-release-1.12.1)

#头文件路径
include_directories(${TEST_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/include
    ${GTEST_SOURCE_DIR}/googletest/include
)

#源文件
aux_source_directory(${TEST_SOURCE_DIR} TEST_SOURCE_DIR_FILE)
aux_source_directory(${PROJECT_SOURCE_DIR} PROJECT_SOURCE_DIR_FILE)
aux_source_directory(${PROJECT_SOURCE_DIR}/src PROJECT_SOURCE_DIR_SRC_FILE)

# 生成可执行文件
add_executable(${PROJECT_SOURCE_DIR}/../out/${PROJECT_NAME} TEST_SOURCE_DIR_FILE PROJECT_SOURCE_DIR_FILE PROJECT_SOURCE_DIR_SRC_FILE)

#链接
target_link_libraries(gtest pthread)
