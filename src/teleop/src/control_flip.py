#!/usr/bin/env python

import rospy
from std_msgs.msg import String
from geometry_msgs.msg import Twist


pub = rospy.Publisher('cmd_vel', Twist, queue_size=10)
rospy.init_node('robot_cmdr')


def callback(data):
    msg = data
    msg.angular.z = msg.angular.z * -1
    pub.publish(msg)

    
rospy.Subscriber("/cmd_mux/cmd_vel", Twist, callback)
rospy.spin()


'''
---
linear: 
  x: -0.0
  y: 0.0
  z: 0.0
angular: 
  x: 0.0
  y: 0.0
  z: -0.4


'''
