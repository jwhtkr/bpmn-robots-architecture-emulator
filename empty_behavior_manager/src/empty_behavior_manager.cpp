/**
 * @File: empty_behavior_manager.cpp
 * @Date: 19 July 2019
 * @Author: James Swedeen
 *
 * @brief
 * Inherits from the BehaviorManager class but has no behavior implementation.
 **/

/* Local Headers */
#include"empty_behavior_manager/empty_behavior_manager.hpp"

/* Architecture Messages */
#include<architecture_msgs/BehaviorStatus.h>

/* Behavior Manager Headers */
#include<behavior_manager/behavior_manager.hpp>

/* C++ Headers */
#include<string>
#include<vector>

EmptyBehaviorManager::EmptyBehaviorManager(const std::string&                    base_uri,
                                           const std::string&                    name,
                                           const std::string&                    camunda_topic,
                                           const std::string&                    status_topic,
                                           const std::string&                    get_resources_topic,
                                           const std::string&                    give_resources_topic,
                                           const std::string&                    update_resources_topic,
                                           const std::string&                    modify_robots_topic,
                                           const behavior_manager::ResourcePool& resources_template)
 : BehaviorManager(base_uri,
                   name,
                   camunda_topic,
                   status_topic,
                   get_resources_topic,
                   give_resources_topic,
                   update_resources_topic,
                   modify_robots_topic,
                   resources_template)
{}

architecture_msgs::BehaviorStatus::Response::Ptr EmptyBehaviorManager::getStatus() const noexcept
{
  architecture_msgs::BehaviorStatus::Response::Ptr output(behavior_manager::BehaviorManager<>::getStatus());

  output->description = "This is a empty behavior made for architecture testing purposes.";

  return output;
}

void EmptyBehaviorManager::runBehavior()
{
  BehaviorManager::runBehavior();
}

/* empty_behavior_manager.cpp */
