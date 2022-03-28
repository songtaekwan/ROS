#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Bool.h"         //boolean data
#include "std_msgs/String.h"
#include "sensor_msgs/Range.h"     //ultrasonic sensor message
#include "geometry_msgs/Twist.h"   //cmd_vel

std_msgs::Bool flag_AEB3;

void UltraSonarCallback3(const sensor_msgs::Range::ConstPtr&msg)
{
	ROS_INFO("Sonar Seq: [%d]", msg->header.seq);
	ROS_INFO("Sonar Range: [%f]", msg->range);
	
	if(msg->range<=1.0)
	{
		ROS_INFO("AEB_Activation!!");
		flag_AEB3.data=true;
	}
	else
	{
		flag_AEB3.data=false;
	}
}
int main (int argc, char **argv)
{
	int count = 0;
	
	ros::init(argc, argv, "aeb_controller_bool");
	
	ros::NodeHandle n;
	
	ros::Rate loop_rate(1);
	
	ros::Subscriber sub3 = n. subscribe("range",1000,UltraSonarCallback3);
	
	ros::Publisher pub_1 = n.advertise<std_msgs::Bool>("Bool1",1000);
	
	
	while (ros::ok())
	{
		pub_1.publish(flag_AEB3);
		loop_rate.sleep();
		ros::spinOnce();
		++count;
	}
	return 0;
}
