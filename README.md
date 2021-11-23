# AY22_RADBOT
    ROS Version: Melodic  
    Ubuntu Version: 18.04 

## Package Descriptions
    1. Velodyne
        - Control for Velodyne Lidar Sensor
        - Pulled Straight from Velodyne Github: https://github.com/ros-drivers/velodyne
        - Start-up Guide: http://wiki.ros.org/velodyne/Tutorials/Getting%20Started%20with%20the%20Velodyne%20VLP16

    2. Microstrain
        - Control for 3DM-GX5 Microstrain INS
        - Pulled Straight from Microstrain Github: https://github.com/LORD-MicroStrain/microstrain_inertial

    3. Realsense
        - Control for Intel Realsense2 Depth Camera
        - Pulled Straight from Intel Github: https://github.com/IntelRealSense/realsense-ros

    4. Kromek
        - Control for Kromek Radiation Detector
        - 

    5. usma_gvrbot
        - Control for gvrbot 
        - Pulled Straight from DI2E bitbucket
        - Requires Top Secret Access to clone repo

    6. ate
        - Control for Autonomous Tunnel Exploration
        - Pulled Straight from DI2E bitbucket
        - Requires Top Secret Access to clone repo

## Initial Setup
    1. git clone <AY22_RADBOT repository>
    2. git checkout development (Switch to development branch)
    3. git clone <ate and usma_gvrbot from DI2E> in src folder
    4. Install dependencies listed below
    5. catkin_make (Compile Workspace)
    6. Highly Recommend installing VSCode or CLion

## Dependencies  
    sudo apt-get install ros-melodic-velodyne
    sudo apt-get install ros-melodic-velodyne-description
    sudo apt-get install ros-melodic-realsense2-camera
    sudo apt-get install ros-melodic-realsense2-description
    sudo apt-get install ros-melodic-teleop-twist-joy
    sudo apt-get install ros-melodic-jackal-description (Google Cartographer)
    sudo apt-get install ros-melodic-microstrain-inertial-driver
    sudo apt-get update

## Running RADBOT
    1. source devel/setup.bash (Adds workspace to ROS path)
    2. roslaunch master.launch

## Git Commands
    1. git pull origin development (Pulls Github code to machine)
    2. <Work on Code>
    3. git add -A (Includes all files in workspace)
    4. git commit -m "Message"
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
    S/N: 943222072817
    Physical Port: 2-1.1-6
    Product ID: 0x0B3A

## 3DM-GX5-45 Microstrain IMU
    S/N: 6251-4220-8566A

## Connection Guide
    Velodyne Lidar
        - Plug USB adapter into a USB hub which is then connected to a Jetson Nano
        - Manually Assign USB hub connection the ip address 192.168.1.111/24 (DGW) similar to the velodyne start-up guide
        - Default frame in rviz is /velodyne

## Other
    List USB connected devices: ll /dev/serial/by-id

BRIX01 On-board Computer: RrcCmp2@
    1. Connect to GVRBOT wifi
        Pass: modern0325
    2. Ping 192.168.0.101
        Wait until connected
    3. ssh gvrbot@192.168.0.101
        pass: modern(recommended) 
    4. New Command line
        export ROS_MASTER_URI=http://192.168.0.101:11311
        ifconfig
        "search for wireless ip (192.168.0.xxx)"
        export ROS_IP=192.168.0.xxx
        rostopic list
        "look for gvrbot topics (if you dont see them, it wont work)
        roslaunch gvrbot xbox360_teleop.launch
