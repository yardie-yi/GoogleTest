cmake_minimum_required(VERSION 3.0)  

#项目名
project(ts_test)

#指定C++版本为C++11
set(CMAKE_CXX_STANDARD 11)

#设置模块路径为变量
set(GTEST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/../../../googletest-release-1.12.1)

#头文件路径
include_directories(${TEST_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/../include
    ${GTEST_SOURCE_DIR}/googletest/include
	${GTEST_SOURCE_DIR}/googletest/include/gtest
    ${PROJECT_SOURCE_DIR}/../../../../TauristarPlatform/src/tauristar_platform/apa_full_stack
    ${PROJECT_SOURCE_DIR}/../../../../TauristarPlatform/src/tauristar_platform/cross_components/eigen3
    ${PROJECT_SOURCE_DIR}/../../../../TauristarPlatformThirdparty/third_party/install/x86_64/opencv_v3.1.0/include
    ${PROJECT_SOURCE_DIR}/../../../../TauristarPlatform/src/tauristar_platform/flow_processor
    ${PROJECT_SOURCE_DIR}/../../../../TauristarPlatform/src/tauristar_platform/basic_util
    ${PROJECT_SOURCE_DIR}/../../../../TauristarPlatformThirdparty/third_party/yaml-cpp/include
)


#链接库路径
link_directories(${GTEST_SOURCE_DIR}/build_pc/lib/)
link_directories(${TEST_SOURCE_DIR})
link_directories(${PROJECT_SOURCE_DIR}/../../../../TauristarPlatform/src/tauristar_platform/build/lib)
link_directories(${PROJECT_SOURCE_DIR}/../../../../TauristarPlatform/src/tauristar_platform/third_party/install/x86_64/opencv_v3.1.0/lib)

# 生成可执行文件
add_executable(ts_test ../main.cpp ../src/ts_test.cpp)

set(TS_LIB
    amathutils_lib
    apa_car_path
    apa_info_if_c
    apa_info_if
    apa_info_process
    apa_park_space_gridmap
    astar_search
    basic_tracker
    basic_util
    bsdlib
    chessDetector_lib
    drlib
    fcwcal
    fcw
    funcgen
    Geographic
    Geographic
    Geographic
    grid_map_core
    grid_map_cv
    kalman_encoder_odom
    kurzer_hybrid_astar
    lanelet2_core
    lanelet2_extension_lib
    lanelet2_io
    lanelet2_projection
    lanelet2_routing
    lanelet2_traffic_rules
    lanelet2_validation
    lib_avm_algobase
    lib_avm_bvc
    lib_avm_calib
    lib_avm_dcal
    lib_avm
    lib_avm_util
    map_file_lib
    motion_planner
    mpc_controller_lib
    optimizer
    pugixml
    pugixml
    pugixml
    qpOASES
    simple_path_planner
    spdlog
    state_machine_lib
    tauristar_c
    tauristar_flowprocessor
    tauristar_geometry
    tauristar_gridmap
    tauristar_hd_gridmap
    tauristar_operations
    tauristar_procedure
    ts_image_geometry
    yaml-cpp
    yaml-cpp
    yaml-cpp
    zlib
)

set (OpenCV_LIBS                                                                                                                                                   
    opencv_features2d
    #opencv_flann
    opencv_highgui
    opencv_imgcodecs
    opencv_imgproc
    opencv_ml
    opencv_objdetect
    opencv_photo
    opencv_shape
    opencv_stitching
    opencv_superres
    opencv_video
    opencv_videoio
    opencv_videostab
    opencv_core
    opencv_calib3d
) 

set(Boost_LIBS
    boost_atomic
    boost_chrono
    boost_date_time
    boost_filesystem
    boost_graph
    boost_log_setup
    boost_log
    boost_prg_exec_monitor
    boost_program_options
    boost_random
    boost_regex
    boost_serialization
    boost_system
    boost_thread
    boost_timer
    boost_unit_test_framework
    boost_wserialization
)

set(LIB_NAMES
        #pages
        #app
        #module
        #aicontrol
        #shader
        #show
        #look
        #datamng
        #bstisp
        #glm_shared
        GLESv2
        wayland-egl
        wayland-client
        wayland-server
        pthread
        freetype
        dl
        amathutils_lib 
        apa_car_path 
        apa_info_if_c 
        apa_info_if 
        apa_info_process 
        apa_park_space_gridmap
        astar_search 
        basic_tracker 
        basic_util 
        chessDetector_lib 
        grid_map_core
        grid_map_cv 
        kalman_encoder_odom kurzer_hybrid_astar 
        tauristar_flowprocessor
        tauristar_gridmap 
        tauristar_hd_gridmap 
        tauristar_operations 
        tauristar_procedure
        tauristar_geometry
        #tauristar-yaml-cpp
        drlib
        fcw 
        fcwcal
        lanelet2_core 
        lanelet2_extension_lib 
        lanelet2_io
        lanelet2_projection 
        lanelet2_routing 
        lanelet2_traffic_rules 
        lanelet2_validation 
        Geographic
        lib_avm_algobase
        lib_avm_bvc 
        lib_avm_calib 
        lib_avm_dcal 
        lib_avm 
        lib_avm_util motion_planner 
        mpc_controller_lib
        #nl2sol 
        optimizer 
        pugixml 
        qpOASES 
        simple_path_planner 
        spdlog 
        state_machine_lib 
        ts_image_geometry 
        yaml-cpp 
        zlib 
        #MNN
        ${OpenCV_LIBS}
        ${Boost_LIBS}
        rt
        avcodec
        avformat
        avutil
        bsdlib
    )

#链接
target_link_libraries(ts_test gtest gtest_main gmock gmock_main pthread ${LIB_NAMES} ${OpenCV_LIBS} ${Boost_LIBS})

#运行可执行文件前需要设置环境变量：
#export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH:/home/yardie/Desktop/TDA4X_master/TauristarPlatformThirdparty/third_party/install/x86_64/opencv_v3.1.0/lib/


