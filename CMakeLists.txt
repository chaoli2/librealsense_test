cmake_minimum_required(VERSION 2.8.3)
project(test)

add_compile_options(-std=c++11)

find_package(
  catkin REQUIRED COMPONENTS
  roscpp
  roslint
)

find_package(
  realsense2
)

catkin_package(
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
  roscpp
  roslint
)

include_directories (
  ${catkin_INCLUDE_DIRS}
)

add_executable(main
  main.cpp
)

add_dependencies(main
  ${${PROJECT_NAME}_EXPORTED_TARGETS} 
  ${catkin_EXPORTED_TARGETS}
)

# first linkage order
# segmentation fault always in this linkage order
target_link_libraries(main
  ${catkin_LIBRARIES}
  realsense2
)

# second linkage order
# segmentation fault only when you use rs API in this linkage order
# uncomment line 9 in main.cpp to see segmentation fault in this linkage order
#target_link_libraries(main
#  realsense2
#  ${catkin_LIBRARIES}
#)
