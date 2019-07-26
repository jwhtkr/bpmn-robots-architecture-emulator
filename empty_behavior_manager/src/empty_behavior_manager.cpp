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

/* Behavior Manager Headers */
#include<behavior_manager/behavior_manager.hpp>

/* C++ Headers */
#include<string>
#include<vector>

EmptyBehaviorManager::EmptyBehaviorManager(const std::string& base_uri,
                                           const std::string& name,
                                           const std::string& topic)
 : BehaviorManager(base_uri, name, topic, std::vector<std::string>(), 1)
{}

uint8_t EmptyBehaviorManager::getBehaviorPriority() const noexcept
{
  return 42;
}

void EmptyBehaviorManager::runBehavior()
{
  BehaviorManager::runBehavior();
}

/* empty_behavior_manager.cpp */
