/**
 * @File: resource_manager_emulator_node.cpp
 * @Date: 25 July 2019
 * @Author: James Swedeen
 *
 * @brief
 * This node will pretend to be the Resource Manager.
 **/

/* Architecture Messages */
#include<architecture_msgs/ResourceRequest.h>

/* Ros Headers */
#include<ros/ros.h>

/* C++ Headers */
#include<string>
#include<mutex>
#include<cstdio>

/* Protects threads */
std::mutex mux;

bool requestCallback(architecture_msgs::ResourceRequest::Request&  req,
                     architecture_msgs::ResourceRequest::Response& res);

void askForResources(ros::ServiceClient& get_resources_srv);

int main(int argc, char** argv)
{
  ros::init(argc, argv, "resource_manager_emulator");
  ros::NodeHandle m_nh;
  ros::NodeHandle p_nh("~");

  std::string        request_topic;
  ros::ServiceServer request_srv;

  std::string        get_resources_topic;
  ros::ServiceClient get_resources_srv;

  // Get topic string from ROS Parameter Server
  p_nh.getParam("request_topic",       request_topic);
  p_nh.getParam("get_resources_topic", get_resources_topic);

  // Connects to rest of architecture
  request_srv       = m_nh.advertiseService(request_topic, requestCallback);
  get_resources_srv = m_nh.serviceClient<architecture_msgs::ResourceRequest>(get_resources_topic);

  ros::spinOnce();

  while(m_nh.ok())
  {
    std::string user_bool = std::string();

    mux.lock();

    ROS_INFO("Would you like to ask for resources back?(y or n defaults to n)");
    std::cin >> user_bool;

    if("y" == user_bool)
    {
      askForResources(get_resources_srv);
    }

    mux.unlock();
    ros::spinOnce();
  }

  exit(EXIT_SUCCESS);
}

bool requestCallback(architecture_msgs::ResourceRequest::Request&  req,
                     architecture_msgs::ResourceRequest::Response& res)
{
  std::unique_lock<std::mutex> lock(mux);
  std::string choice;

  ROS_INFO("Resource Request received.");
  ROS_INFO("Request body:");
  ROS_INFO_STREAM(req);

  ROS_INFO("Options are;\n  1. Return full success\n  2. Return required success\n  3. Return failure");
  std::cin >> choice;

  switch(std::stoi(choice))
  {
    case 1:
      ROS_INFO("Returning full success.");
      res.success = true;
      res.roles = req.roles;
      ROS_INFO("Response body:");
      ROS_INFO_STREAM(res);
      return true;
      break;
    case 2:
      ROS_INFO("Returning required success.");
      res.success = true;
      for(auto roles_it = req.roles.cbegin(); roles_it != req.roles.cend(); roles_it++)
      {
        if(roles_it->required)
        {
          res.roles.emplace_back(*roles_it);
        }
      }
      ROS_INFO("Response body:");
      ROS_INFO_STREAM(res);
      return true;
      break;
    case 3:
      ROS_INFO("Returning failure.");
      res.success = false;
      ROS_INFO("Response body:");
      ROS_INFO_STREAM(res);
      return true;
      break;
    default:
      ROS_INFO("Choice not recognized. Returning full success.");
      res.success = true;
      res.roles = req.roles;
      ROS_INFO("Response body:");
      ROS_INFO_STREAM(res);
      return true;
      break;
  }
}

void askForResources(ros::ServiceClient& get_resources_srv)
{
  architecture_msgs::ResourceRequest msg;
  std::string role_name = std::string();

  ROS_INFO("Value for behavior_id:");
  std::cin >> msg.request.behavior_id;

  do
  {
    std::string resource_name = std::string();

    ROS_INFO("Name of role (if 'done' is given no more roles will be added to this request):");
    std::cin >> role_name;

    if("done" != role_name)
    {
      msg.request.roles.emplace_back();
      msg.request.roles.back().name = role_name;

      do
      {
        ROS_INFO("name of resource (if 'done' is given no more resources will be added to this role):");
        std::cin >> resource_name;

        if("done" != resource_name)
        {
          msg.request.roles.back().resources.emplace_back();
          msg.request.roles.back().resources.back().name = resource_name;
        }
      } while("done" != resource_name);
    }
  } while("done" != role_name);

  ROS_INFO("Request body:");
  ROS_INFO_STREAM(msg.request);

  if(!get_resources_srv.call(msg))
  {
    ROS_ERROR("Failed to request resources.");
  }

  ROS_INFO("Response body:");
  ROS_INFO_STREAM(msg.response);
}

/* resource_manager_emulator_node.cpp */
