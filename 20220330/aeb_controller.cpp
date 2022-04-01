#include "std_msgs/Bool.h"         //boolean data
#include "std_msgs/String.h"
#include "sensor_msgs/Range.h"     //ultrasonic sensor message
#include "geometry_msgs/Twist.h"   //cmd_vel
#include "std_msgs/Float32.h"
#include "nav_msgs/Odometry.h"

std_msgs::Bool flag_AEB;
std_msgs::Float32 delta_range;        
std_msgs::Float32 old_sonar_range;
geometry_msgs::Twist cmd_vel_msg;  

nav_msgs::Odometry estimated_odom; 

void odomCallback(const nav_msgs::Odometry& msg)
{
	estimated_odom.twist.twist.angular.x= msg.twist.twist.angular.x;
	estimated_odom.twist.twist.angular.y= msg.twist.twist.angular.x;
	estimated_odom.twist.twist.angular.z= msg.twist.twist.angular.z;
	
	estimated_odom.twist.twist.linear.x= msg.twist.twist.linear.x;
	estimated_odom.twist.twist.linear.y= msg.twist.twist.linear.y;
	estimated_odom.twist.twist.linear.z= msg.twist.twist.linear.z;
}

void UltraSonarCallback(const sensor_msgs::Range::ConstPtr&msg)
{
	ROS_INFO("Sonar Seq: [%d]", msg->header.seq);
	ROS_INFO("Sonar Range: [%f]", msg->range);
	
	if(msg->range<=1.8)
	{
		ROS_INFO("AEB_Activation!!");
		flag_AEB.data=true;
	}
	else
	{
		flag_AEB.data=false;
	}
}

void UltraSonarCallback2(const sensor_msgs::Range::ConstPtr&msg)
{
	ROS_INFO("Sonar2 Seq: [%d]", msg->header.seq);
	ROS_INFO("Sonar2 Range: [%f]", msg->range);
}

void CarControlCallback(const geometry_msgs::Twist&msg)
{
	ROS_INFO("Cmd_vel : linear_x [%f]", msg.linear.x);
	
	cmd_vel_msg=msg;
	//ROS_INFO("Cmd_vel : linear_x [%f]", cmd_vel_msg.linear.x);
}
int main (int argc, char **argv)
{
	int count = 0;
	
	ros::init(argc, argv, "aeb_controller");
	
    ros::NodeHandle n;
	
	std::string odom_sub_topic = "/ackermann_steering_controller/odom";
	
	ros::Subscriber sub = n. subscribe("/range",1000,UltraSonarCallback);
	ros::Subscriber sonar_sub = n. subscribe("/RangeSonar1",1000,UltraSonarCallback2);
	ros::Subscriber cmd_vel_sub = n. subscribe("/cmd_vel",10,&CarControlCallback);
	ros::Subscriber sub_odom = n.subscribe("odom_sub_topic", 10, &odomCallback);
	
	
	ros::Publisher pub_aeb_activation_flag = n.advertise<std_msgs::Bool>("/aeb_activation_flag",1);
	ros::Publisher pub_cmd_vel = n.advertise<geometry_msgs::Twist>("/ackermann_steering_controller/cmd_vel",10);
	ros::Publisher pub_estimated_odom = n.advertise<nav_msgs::Odometry>("/estimated_odom",10);
	
	
	
	ros::Rate loop_rate(10); 
	
	while (ros::ok())
	{
		if((count&10)==0)
		{
			pub_aeb_activation_flag.publish(flag_AEB);
		}
		
		if(flag_AEB.data == true)
		{
			if(cmd_vel_msg.linear.x > 0) 
			{
				cmd_vel_msg.linear.x = 0;
			}
			pub_cmd_vel.publish(cmd_vel_msg);
		}
		else
		{
			pub_cmd_vel.publish(cmd_vel_msg);
		}
		
		pub_estimated_odom.publish(estimated_odom);
		
		loop_rate.sleep();
		ros::spinOnce();
		++count;
	}
	return 0;
} 
