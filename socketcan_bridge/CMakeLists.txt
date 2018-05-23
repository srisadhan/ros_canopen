cmake_minimum_required(VERSION 2.8.3)
project(socketcan_bridge)

find_package(catkin REQUIRED
  COMPONENTS
    std_msgs
    roscpp
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)
if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)

  add_rostest_gtest(test_to_socketcan
    test/to_socketcan.test
    test/to_socketcan_test.cpp
  )
  target_link_libraries(test_to_socketcan
    ${catkin_LIBRARIES}
  )
endif()
