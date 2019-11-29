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

/* BehaviorManager Headers */
#include<behavior_manager/behavior_pool.hpp>

/* ROS Headers */
#include<ros/ros.h>

/* C++ Headers */
#include<memory>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "empty_behavior_manager_node");
  ros::NodeHandle m_nh;
  ros::NodeHandle param_nh("~");

  behavior_manager::BehaviorPool<EmptyBehaviorManager> test(param_nh);

/*  behavior_manager::BehaviorPool<EmptyBehaviorManager> test("empty_behavior",
                                                            "http://localhost:8080/",
                                                            listen_topic,
                                                            status_topic,
                                                            get_resources_topic,
                                                            give_resources_topic,
                                                            update_resources_topic,
                                                            modify_robots_topic,
                                                            config_file_path);*/
  ros::Rate loop_rate(30);

  while(m_nh.ok())
  {
    ros::spin();
    loop_rate.sleep();
  }

  exit(EXIT_SUCCESS);
}
