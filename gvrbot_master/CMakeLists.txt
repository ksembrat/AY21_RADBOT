cmake_minimum_required(VERSION 2.8.3)
project(gvrbot_bringup)

find_package(catkin REQUIRED COMPONENTS roslaunch)

catkin_package()


install(DIRECTORY launch Media worlds
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
