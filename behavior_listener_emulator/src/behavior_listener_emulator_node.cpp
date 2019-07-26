/**
 * @File: behavior_manager_emulator_node.cpp
 * @Date: 26 July 2019
 * @Author: James Swedeen
 *
 * @brief
 * Pretends to be the Behavior Manager.
 **/

/* Architecture Messages */
#include<architecture_msgs/Behavior.h>

/* ROS Headers */
#include<ros/ros.h>

/* C++ Headers */
#include<string>
#include<cstdio>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "behavior_manager_emulator");
  ros::NodeHandle m_nh;
  ros::NodeHandle p_nh("~");

  ros::Publisher notify_pub;

  architecture_msgs::Behavior msg;

  std::string notifying_topic;

  p_nh.getParam("notifying_topic", notifying_topic);

  notify_pub = m_nh.advertise<architecture_msgs::Behavior>(notifying_topic, 10);

  while(m_nh.ok())
  {
    std::string from_user = std::string();

    if(std::string() != msg.name)
    {
      ROS_INFO("Do you want to republish the same message? (y or n)");
      std::cin >> from_user;
    }

    if("y" != from_user)
    {
      ROS_INFO("Topic (if n is entered it will default to the previous topic value):");
      std::cin >> from_user;
      if("n" != from_user)
      {
        msg.topic = from_user;
      }

      ROS_INFO("Name (if n is entered it will default to the previous topic value):");
      std::cin >> from_user;
      if("n" != from_user)
      {
        msg.name = from_user;
      }

      ROS_INFO("Instance_id (if n is entered it will default to the previous topic value):");
      std::cin >> from_user;
      if("n" != from_user)
      {
        msg.instance_id = from_user;
      }

      ROS_INFO("Status (if n is entered it will default to the previous topic value) (NEW == 2, CANCELED == 1):");
      std::cin >> from_user;
      if("n" != from_user)
      {
        msg.status = std::stoi(from_user);
      }
    }

    ROS_INFO("Published Message:");
    ROS_INFO_STREAM(msg);
    notify_pub.publish(msg);

    ros::spinOnce();
  }

  exit(EXIT_SUCCESS);
}

/* behavior_manager_emulator_node.cpp */
