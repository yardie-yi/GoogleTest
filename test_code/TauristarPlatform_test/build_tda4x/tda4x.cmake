# this one is important
SET(CMAKE_SYSTEM_NAME Linux)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)

#
#build lib for linux arm running on a15 (vsdk)
#
#set(HOME /home/aitronx)
OPTION(BUILD_TDA4 "build TDA4 target" ON)

#set(TI_SW_ROOT ${HOME}/psdk_rtos_auto_j7_07_00_00_11)
#set(TARGET_FS_PATH ${TI_SW_ROOT}/os_tools/linux/targetfs)
set(TARGET_FS_PATH ${TI_SW_ROOT}/targetfs)

set(TOOLCHAIN_DIR ${TI_SW_ROOT}/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu)  
set(CMAKE_C_COMPILER ${TOOLCHAIN_DIR}/bin/aarch64-none-linux-gnu-gcc)  
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_DIR}/bin/aarch64-none-linux-gnu-g++)  
set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_DIR})  
set(ARM_LINUX_SYSROOT ${TOOLCHAIN_DIR} CACHE PATH "ARM cross compilation system root")


add_compile_options(-fPIC)


