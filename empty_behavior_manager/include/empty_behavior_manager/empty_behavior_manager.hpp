/**
 * @File: empty_behavior_manager.hpp
 * @Date: 19 July 2019
 * @Author: James Swedeen
 *
 * @brief
 * Inherits from the BehaviorManager class but has no behavior implementation.
 **/

#ifndef EMPTY_BEHAVIOR_MANAGER_EMPTY_BEHAVIOR_MANAGER_HPP
#define EMPTY_BEHAVIOR_MANAGER_EMPTY_BEHAVIOR_MANAGER_HPP

/* Behavior Manager Headers */
#include<behavior_manager/behavior_manager.hpp>

/* Architecture Messages */
#include<architecture_msgs/BehaviorStatus.h>

/* C++ Headers */
#include<string>

class EmptyBehaviorManager : public behavior_manager::BehaviorManager<>
{
public:
  /**
   * @Default Constructor
   **/
  EmptyBehaviorManager() = delete;
  /**
   * @Copy Constructor
   **/
  EmptyBehaviorManager(const EmptyBehaviorManager&) = delete;
  /**
   * @Move Constructor
   **/
  EmptyBehaviorManager(EmptyBehaviorManager&&) = delete;
  /**
   * @Constructor
   **/
  EmptyBehaviorManager(const std::string&                    base_uri,
                       const std::string&                    name,
                       const std::string&                    camunda_topic,
                       const std::string&                    status_topic,
                       const std::string&                    get_resources_topic,
                       const std::string&                    give_resources_topic,
                       const std::string&                    update_resources_topic,
                       const std::string&                    modify_robots_topic,
                       const behavior_manager::ResourcePool& resources_template);
  /**
   * @Deconstructor
   **/
  ~EmptyBehaviorManager() override = default;
  /**
   * @Assignment Operators
   **/
  EmptyBehaviorManager& operator=(const EmptyBehaviorManager&) = delete;
  EmptyBehaviorManager& operator=(EmptyBehaviorManager&&)      = delete;
  /**
   * @get
   **/
  architecture_msgs::BehaviorStatus::Response::Ptr getStatus()           const noexcept override;
protected:
  /**
   * @runBehavior
   **/
  void runBehavior() override;
};

#endif
/* empty_behavior_manager.hpp */
