BRIX01 On-board Computer: RrcCmp2@

This guide covers 

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