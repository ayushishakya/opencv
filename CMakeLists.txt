cmake_minimum_required(VERSION 2.8.3)
project(opencv)
find_package(OpenCV REQUIRED)

add_executable(cfar src/cfar.cpp)
target_link_libraries( cfar ${OpenCV_LIBS})

add_executable(t_contour src/thermal_contour.cpp)
target_link_libraries( t_contour ${OpenCV_LIBS})

add_executable(t_image src/thermal_image.cpp)
target_link_libraries( t_image ${OpenCV_LIBS})

add_executable(fort src/fortress.cpp)
target_link_libraries(fort ${OpenCV_LIBS})

add_executable(cfarAlgo src/cfarAlgo.cpp)
target_link_libraries(cfarAlgo ${OpenCV_LIBS})


add_executable(kalman_cfar src/CFARnKF.cpp)
target_link_libraries(kalman_cfar ${OpenCV_LIBS})

add_executable(KFtrack src/KFtrack.cpp)
target_link_libraries(KFtrack ${OpenCV_LIBS})

add_executable(histogram src/histogram.cpp)
target_link_libraries(histogram ${OpenCV_LIBS})

add_executable(blur src/Smoothing.cpp)
target_link_libraries(blur ${OpenCV_LIBS})

add_executable(col1 src/colonizer1.cpp)
target_link_libraries(col1 ${OpenCV_LIBS})

add_executable(thresh src/threshold.cpp)
target_link_libraries(thresh ${OpenCV_LIBS})

add_executable(ycrcb src/Ycrcb.cpp)
target_link_libraries(ycrcb ${OpenCV_LIBS})

add_executable(segm src/segmentation.cpp)
target_link_libraries(segm ${OpenCV_LIBS})

add_executable(t_speed src/thermal_speed.cpp)
target_link_libraries(t_speed ${OpenCV_LIBS})
