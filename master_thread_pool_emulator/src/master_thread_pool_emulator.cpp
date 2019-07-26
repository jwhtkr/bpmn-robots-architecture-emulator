
/* Architecture Messages */
#include <architecture_msgs/ModifyNodes.h>

/* ROS Headers */
#include <ros/ros.h>

/* C++ Headers */
#include <string>


bool emulate(architecture_msgs::ModifyNodes::Request &req, architecture_msgs::ModifyNodes::Response &res);

int main(int argc, char **argv)
{
  ros::init(argc, argv, "master_thread_pool_emulator");
  ros::NodeHandle nh;

  std::string request_topic;
  ros::ServiceServer request_server;

  nh.getParam("request_topic", request_topic);

  request_server = nh.advertiseService(request_topic, emulate);

  ros::Rate loop_rate(50);
  while (nh.ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }
  exit(EXIT_SUCCESS);
}

bool emulate(architecture_msgs::ModifyNodes::Request &req, architecture_msgs::ModifyNodes::Response &res)
{
  ROS_INFO("Recieved Message:");
  ROS_INFO_STREAM(req);
  return true;
}