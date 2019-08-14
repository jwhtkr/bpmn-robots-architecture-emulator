/* Architecture Messages */
#include <architecture_msgs/ModifyNodes.h>

/* ROS Headers */
#include <ros/ros.h>

/* C++ Headers */
#include <string>

bool requestCallback(architecture_msgs::ModifyNodesRequest &req, architecture_msgs::ModifyNodesResponse &res);

int main(int argc, char **argv)
{
  ros::init(argc, argv, "machine_pool_emulator_node");
  ros::NodeHandle nh;
  ros::NodeHandle p_nh("~");

  std::string request_topic;
  ros::ServiceServer request_server;

  p_nh.getParam("request_topic", request_topic);

  request_server = nh.advertiseService(request_topic, requestCallback);

  ROS_INFO("I am %s", ros::this_node::getNamespace().c_str());

  ros::Rate loop_rate(50);
  while (nh.ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }
  exit(EXIT_SUCCESS);
}

bool requestCallback(architecture_msgs::ModifyNodesRequest &req, architecture_msgs::ModifyNodesResponse&)
{
  ROS_INFO("Recieved Message:");
  ROS_INFO_STREAM(req);

  return true;
}
