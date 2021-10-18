# AY22_RADBOT
ROS Version: Melodic  
Ubuntu Version: 18.04 

## Package Descriptions
    1. Velodyne
        - Control for Velodyne Lidar Sensor
        - Pulled Straight from Velodyne Github: https://github.com/ros-drivers/velodyne
        - Start-up Guide: http://wiki.ros.org/velodyne/Tutorials/Getting%20Started%20with%20the%20Velodyne%20VLP16

    2. Realsense
        - Control for Intel Realsense2 Depth Camera
        - Pulled Straight from Intel Github: https://github.com/IntelRealSense/realsense-ros

    3. Kromek
        -
        - 

    4. gvrbot
        - Control for gvrbot 
        - Pulled Straight from West Point Github: https://github.com/westpoint-robotics/usma_gvrbot

    

## Initial Setup
    1. git clone <AY22_RADBOT repository>
    2. git checkout development (Switch to development branch)
    6. Install dependencies listed below
    7. catkin_make (Compile Workspace)
    8. Highly Recommend installing VSCode or CLion

## Dependencies  
    sudo apt-get install ros-melodic-velodyne
    sudo apt-get install ros-melodic-velodyne-description
    sudo apt-get install ros-melodic-realsense2-camera
    sudo apt-get install ros-melodic-realsense2-description
    sudo apt-get install ros-melodic-teleop-twist-joy
    sudo apt-get install ros-melodic-jackal-description (Google Cartographer)

## Running RADBOT
    1. source devel/setup.bash (Adds workspace to ROS path)
    2. roslaunch master.launch

## Git Commands
    1. git pull origin development (Pulls Github code to machine)
    2. <Work on Code>
    3. git add -A (Includes all files in workspace)
    4. git commit -m (Include a commit message)
    5. git push origin development (Pushes machine code to Github)
    6. Use git token from Github as password
    
## Simulating RADBOT
    roslaunch gvrbot_gazebo gvrbot_world.launch
    roslaunch gvrbot_viz view_robot.launch

## Velodyne Lidar (VLP16 Puck)
    IP Address: 192.168.1.201
    Subnet Mask: 255.255.255.0
    Default Gateway: 192.168.1.111
    Data Port: 2368
    S/N: AE17711588
    MAC: 60-76-88-10-2d-44

## Intel RealSense2 Depth Camera (D435)


## Connection Guide
BRIX01 On-board Computer: RrcCmp2@
    1. Connect to GVRBOT wifi
        Pass: modern0325
    2. Ping 192.168.0.101
        Wait until connected
    3. ssh gvrbot@192.168.0.101
        pass: modern
    4. New Command line
        export ROS_MASTER_URI=http://192.168.0.101:11311
        ifconfig
        "search for wireless ip (192.168.0.xxx)"
        export ROS_IP=192.168.0.xxx
        rostopic list
        "look for gvrbot topics (if you dont see them, it wont work)
        roslaunch gvrbot xbox360_teleop.launch
