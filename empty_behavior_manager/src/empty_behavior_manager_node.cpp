/**
 * @File: empty_behavior_manager_node.cpp
 * @Date: 19 July 2019
 * @Author: James Swedeen
 *
 * @brief
 * Simply makes an instance of the EmptyBehavorManager class for testing.
 **/

/* Local Headers */
#include"empty_behavior_manager/empty_behavior_manager.hpp"

/* ROS Headers */
#include<ros/ros.h>

/* C++ Headers */
#include<memory>
#include<cstdio>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "empty_behavior_manager_node");
  ros::NodeHandle m_nh;

  std::unique_ptr<EmptyBehaviorManager> test(new EmptyBehaviorManager("http://localhost:8080/", "worker_id", "topic"));

  std::cin.get();

  test.reset();

  std::cin.get();

  exit(EXIT_SUCCESS);
}
