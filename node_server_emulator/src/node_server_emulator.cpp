
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
bool startNodeEmulator(node_server_msgs::StartNode::Request &req, node_server_msgs::StartNode::Response &res);
bool startNodeListEmulator(node_server_msgs::StartNodeList::Request &req, node_server_msgs::StartNodeList::Response &res);
bool killNodeEmulator(node_server_msgs::Kill::Request &req, node_server_msgs::Kill::Response &res);
bool wakeNodeEmulator(node_server_msgs::Wake::Request &req, node_server_msgs::Wake::Response &res);
bool sleepNodeEmulator(node_server_msgs::Sleep::Request &req, node_server_msgs::Sleep::Response &res);





int main(int argc, char **argv)
{
  ros::init(argc, argv, "node_server_emulator");
  ros::NodeHandle nh;
  ros::NodeHandle p_nh("~");
  ros::ServiceServer start_srv, start_list_srv, kill_srv, sleep_srv, wake_srv;
  std::string start_node_srv_topic, start_node_list_srv_topic, kill_srv_topic, wake_srv_topic, sleep_srv_topic;



  start_srv = nh.advertiseService("start_node_srv_topic", startNodeEmulator);
  start_list_srv = nh.advertiseService("start_node_list_srv_topic",startNodeListEmulator);
  kill_srv = nh.advertiseService("kill_srv_topic", killNodeEmulator);
  sleep_srv = nh.advertiseService("sleep_srv_topic", sleepNodeEmulator);
  wake_srv = nh.advertiseService("wake_srv_topic", wakeNodeEmulator);
 
  ros::Rate loop_rate(30);

  while(nh.ok())
  {
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}

bool startNodeEmulator(node_server_msgs::StartNode::Request &req, node_server_msgs::StartNode::Response &res)
{
  res.results.name = req.node.name;
  res.results.type = 1;
  res.results.pid = 8008135;
  ROS_INFO("Node Started with pid %d",res.results.pid);
  return true;
}
bool startNodeListEmulator(node_server_msgs::StartNodeList::Request &req, node_server_msgs::StartNodeList::Response &res)
{
  node_server_msgs::Target helper;

  for(int i = 0; i < req.nodes.size(); i++)
  {
    helper.name = req.nodes[i].name;
    helper.type = 1;
    helper.pid = rand() % 5;
    res.results.push_back(helper);
    ROS_INFO("Node Started with pid %d",res.results[i].pid);
  }
  ROS_INFO("List of Nodes started");
  return true;
}
bool killNodeEmulator(node_server_msgs::Kill::Request &req, node_server_msgs::Kill::Response &res)
{
  node_server_msgs::TargetFailure helper;
  helper.error_code = 0;
  for(int i = 0; i < req.targets.size(); i++)
  {
    res.failed.push_back(helper);
    ROS_INFO("Node \" %s \" killed",req.targets[i].name.c_str());
  }

  ROS_INFO("Nodes killed successfully");
  return true;
}
bool wakeNodeEmulator(node_server_msgs::Wake::Request &req, node_server_msgs::Wake::Response &res)
{
  node_server_msgs::TargetFailure helper;
  helper.error_code = 0;
  for(int i = 0; i < req.targets.size(); i++)
  {
    res.failed.push_back(helper);
    ROS_INFO("Node \" %s \" woke",req.targets[i].name.c_str());
  }
  ROS_INFO("Nodes woke successfully");
  return true;
}
bool sleepNodeEmulator(node_server_msgs::Sleep::Request &req, node_server_msgs::Sleep::Response &res)
{
  node_server_msgs::TargetFailure helper;
  helper.error_code = 0;
  
  for(int i = 0; i < req.targets.size();i++)
  {
    res.failed.push_back(helper);
    ROS_INFO("Node \" %s \" slept",req.targets[i].name.c_str());
  }
  ROS_INFO("Nodes slept successfully");
  return true;
}

