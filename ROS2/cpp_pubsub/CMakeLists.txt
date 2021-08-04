cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(OpenCV 4 QUIET
  COMPONENTS
    opencv_core
    opencv_imgproc
    opencv_imgcodecs
  CONFIG
)
if(NOT OpenCV_FOUND)
  find_package(OpenCV 3 REQUIRED
    COMPONENTS
      opencv_core
      opencv_imgproc
      opencv_imgcodecs
    CONFIG
  )
endif()
find_package(cv_bridge REQUIRED)

add_executable(talker src/pub_image.cpp)
ament_target_dependencies(talker rclcpp std_msgs sensor_msgs)
add_executable(listener src/sub_image.cpp)
ament_target_dependencies(listener rclcpp std_msgs sensor_msgs OpenCV cv_bridge)

install(TARGETS
  talker
  listener
  DESTINATION lib/${PROJECT_NAME})

ament_package()
