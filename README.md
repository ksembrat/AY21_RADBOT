# AY22_RADBOT

## Package Descriptions
    01. gvrbot_master
        -> Master control point. Includes the launch file to launch all other launch files.
    02. gvrbot_camera
        -> Launch file for D435 realsense depth camera
    03. gvrbot_lidar
        -> Launch file for Velodyne Lidar
    04. gvrbot_control
        -> Manual control with Xbox360 controller
    05. gvrbot_msgs
        -> Parameters for all gvrbot messages
    06. gvrbot_gazebo
        -> For control of RADBOT simulation
    07. gvrbot_description
        -> Includes sensor config files and basic descriptions of the frame to use in simulations
    08. gvrbot_viz
        -> For configuration of Rviz
    09. gvrbot_navigation
        -> For SLAM
    10. gvrbot_cartographer_navigation
        -> For SLAM using Google Cartographer
    11. gvrbot_sensor_test
        -> Converts point cloud to laser scan
    12. gvrbot_web_server
        -> Launches web server
    13. kromekEx
        -> Files for Kromek sensors

ROS Version: Melodic  
Ubuntu Version: 16.04  

## Initial Setup
    1. Clone this repository
    2. Install dependencies located below
    3. Set Udev rule for Inertial Measurement Unit (Microstrain 3DM-GX5)
    4. Follow Connection_guide.md
    
## Simulating RADBOT
    roslaunch gvrbot_gazebo gvrbot_world.launch
    roslaunch gvrbot_viz view_robot.launch

## Running on actual robot
    roslaunch gvrbot_master master.launch

## Dependencies 
    velodyne_description: 
    sudo apt-get install ros-melodic-velodyne-description 
    realsense2-description: 
    sudo apt-get install ros-melodic-realsense2-description 
