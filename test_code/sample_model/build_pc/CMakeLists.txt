cmake_minimum_required(VERSION 3.0)  

#项目名
project(mytest)

#指定C++版本为C++11
set(CMAKE_CXX_STANDARD 11)

#设置模块路径为变量
set(TEST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../sample_src_code)
set(GTEST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../googletest-release-1.12.1)

#头文件路径
include_directories(${TEST_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/../include
    ${GTEST_SOURCE_DIR}/googletest/include
	${GTEST_SOURCE_DIR}/googletest/include/gtest
)


#链接库路径
link_directories(${GTEST_SOURCE_DIR}/build_pc/lib/)
link_directories(${TEST_SOURCE_DIR})

# 生成可执行文件
add_executable(mytest ../main.cpp ../src/mytest.cpp)
#链接
target_link_libraries(mytest testsrc gtest gtest_main gmock gmock_main pthread)




