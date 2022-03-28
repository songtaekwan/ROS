#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Bool.h"         //boolean data
#include "std_msgs/String.h"
#include "sensor_msgs/Range.h"     //ultrasonic sensor message
#include "geometry_msgs/Twist.h"   //cmd_vel

std_msgs::Bool flag_AEB3;

void UltraSonarCallback4(const sensor_msgs::Bool::ConstPtr&msg)
{
	ROS_INFO("Sonar Seq: [%d]", msg->header.seq);
	ROS_INFO("Sonar Range: [%f]", msg->Bool);
	
	if(msg->data)
	{
		ROS_INFO("true");
		
	}
	else
	{
	    ROS_INFO("false");
	}
}
int main (int argc, char **argv)
{
	int count = 0;
	
	ros::init(argc, argv, "aeb_controller_bool");
	
	ros::NodeHandle n;
	
	ros::Rate loop_rate(1);
	
	ros::Subscriber sub4 = n. subscribe("Bool1",1000,UltraSonarCallback4);
	
	
	
	while (ros::ok())
	{
		loop_rate.sleep();
		ros::spinOnce();
		++count;
	}
	return 0;
}
