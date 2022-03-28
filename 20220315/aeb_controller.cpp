#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Bool.h"         //boolean data
#include "std_msgs/String.h"
#include "sensor_msgs/Range.h"     //ultrasonic sensor message
#include "geometry_msgs/Twist.h"   //cmd_vel

std_msgs::Bool flag_AEB;
std_msgs::Bool flag_AEB2;

void UltraSonarCallback(const sensor_msgs::Range::ConstPtr&msg)
{
	ROS_INFO("Sonar Seq: [%d]", msg->header.seq);
	ROS_INFO("Sonar Range: [%f]", msg->range);
	
	if(msg->range<=1.0)
	{
		ROS_INFO("AEB_Activation!!");
		flag_AEB.data=true;
	}
	else
	{
		flag_AEB.data=false;
	}
}
void UltraSonarCallback2(const sensor_msgs::Range::ConstPtr&msg2)
{
	ROS_INFO("Sonar Seq: [%d]", msg2->header.seq);
	ROS_INFO("Sonar Range: [%f]", msg2->range);
	
	if(msg2->range<=1.0)
	{
		ROS_INFO("AEB_Activation2!!");
		flag_AEB2.data=true;
	}
	else
	{
		flag_AEB2.data=false;
	}
}
int main (int argc, char **argv)
{
	int count = 0;
	
	ros::init(argc, argv, "aeb_controller");
	
	ros::NodeHandle n;
	
	ros::Rate loop_rate(1); //10
	
	ros::Subscriber sub = n. subscribe("range",1000,UltraSonarCallback);
	ros::Subscriber sub2 = n. subscribe("RangeSonar1",1000,UltraSonarCallback2);
	
	while (ros::ok())
	{
		loop_rate.sleep();
		ros::spinOnce();
		++count;
	}
	return 0;
}
