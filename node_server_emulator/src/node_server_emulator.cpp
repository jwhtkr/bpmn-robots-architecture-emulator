

/* Architecture Messages */
#include "node_server_msgs/Kill.h"
#include "node_server_msgs/Sleep.h"
#include "node_server_msgs/StartNode.h"
#include "node_server_msgs/StartNodeList.h"
#include "node_server_msgs/Wake.h"

#include "node_server_msgs/EndedNode.h"
#include "node_server_msgs/Remap.h"
#include "node_server_msgs/Target.h"

/* ROS Headers */
#include <ros/ros.h>

/* C++ Headers */
#include <string>
int main(int argc, char **argv)
{
  ros::init(argc, argv, "node_server_emulator");
  ros::NodeHandle nh;
  ros::NodeHandle p_nh("~");

  std::string start_node_srv_topic, start_node_list_srv_topic, kill_srv_topic, wake_srv_topic, sleep_srv_topic;

  return 0;
}
