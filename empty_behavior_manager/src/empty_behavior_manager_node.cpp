/**
 * @File: empty_behavior_manager_node.cpp
 * @Date: 19 July 2019
 * @Author: James Swedeen
 *
 * @brief
 * Simply makes an instance of the BehaviorPool class templated to the EmptyBehavorManager class for testing.
 **/

/* Local Headers */
#include"empty_behavior_manager/empty_behavior_manager.hpp"

/* BehaviorPool */
#include<behavior_pool/behavior_pool.hpp>

/* ROS Headers */
#include<ros/ros.h>

/* C++ Headers */
#include<memory>
#include<cstdio>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "empty_behavior_manager_node");
  ros::NodeHandle m_nh;
  ros::NodeHandle p_nh("~");

  std::string listen_topic;

  p_nh.getParam("listen_topic", listen_topic);

  BehaviorPool<EmptyBehaviorManager> test(listen_topic, "empty_behavior", "http://localhost:8080/");

  ros::Rate loop_rate(1);

  while(m_nh.ok())
  {
    ros::spin();
    loop_rate.sleep();
  }

  exit(EXIT_SUCCESS);
}
