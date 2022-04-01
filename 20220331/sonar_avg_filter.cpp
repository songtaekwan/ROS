#include "ros/ros.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Bool.h"        
#include "std_msgs/String.h"
#include "sensor_msgs/Range.h"    
#include "geometry_msgs/Twist.h"  
#include "std_msgs/Float32.h"
#include "nav_msgs/Odometry.h"

float sum = 0;
float c = 0;
float range_data = 0;
std_msgs::Float32 average;


void UltraSonarCallback(const sensor_msgs::Range::ConstPtr&msg)
{ 
  range_data = msg-> range;
  if(c<5)
  {
	 sum = sum + range_data;
	 c++;
  }
  else
  {
	 average.data = sum / 5;
	 sum = 0;
	 c = 0; 
  }
  ROS_INFO("sonar avg: [%f]", average.data);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "sonar_avg_filter");
  ros::NodeHandle n;
  
  
  ros::Subscriber sub = n. subscribe("/range",1000,UltraSonarCallback);
  
  ros::Publisher pub_sonar_avg = n. advertise<std_msgs::Float32>("/range_avg",1000);
  
  ros::Rate loop_rate(1);

  int count = 0;
  
  while (ros::ok())
  {
    
   pub_sonar_avg.publish(average);

    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
    return 0;
}
