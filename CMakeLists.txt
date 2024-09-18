cmake_minimum_required(VERSION 3.8)
project(mess2_flir_conversions)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem)
find_package(OpenCV REQUIRED)

find_package(rclcpp REQUIRED)
find_package(cv_bridge REQUIRED)

include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${OpenCV_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIRS}
)

add_library(_flir_conversions SHARED src/conversions.cpp)
add_executable(demo1 src/demo1.cpp)

target_link_libraries(demo1 _flir_conversions)

ament_target_dependencies(
  _flir_conversions
  "Boost"
  "OpenCV"
  "rclcpp"
  "cv_bridge"
)

ament_target_dependencies(
  demo1
  "rclcpp"
  "cv_bridge"
)

install(
  TARGETS _flir_conversions 
  EXPORT export_mess2_flir_conversions
  DESTINATION lib
)

install(
  TARGETS demo1
  EXPORT export_mess2_flir_conversions
  DESTINATION lib/${PROJECT_NAME}
)

install(
  DIRECTORY launch/
  DESTINATION share/${PROJECT_NAME}/launch
)

install(
  DIRECTORY config/
  DESTINATION share/${PROJECT_NAME}/config
)

install(
  DIRECTORY include/
  DESTINATION include
)

ament_export_targets(export_mess2_flir_conversions)
ament_package()