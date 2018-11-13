#include <ros/ros.h>
#include <iostream>

#include <librealsense2/rs.h>

int main(int argc, char **argv)
{
  //uncomment this line to see changing linkage order will not help if you use realsense API
  //std::cout << rs2_get_api_version(nullptr) << std::endl;

  ros::init(argc, argv, "test");
  ros::NodeHandle nh_;     //segmentation fault 
  std::cout << "Done" << std::endl;
}
