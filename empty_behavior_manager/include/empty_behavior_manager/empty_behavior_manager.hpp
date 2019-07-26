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

/* C++ Headers */
#include<string>

class EmptyBehaviorManager : public BehaviorManager<>
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
  EmptyBehaviorManager(const std::string& base_uri,
                       const std::string& name,
                       const std::string& topic);
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
  uint8_t getBehaviorPriority() const noexcept override;
protected:
  /**
   * @runBehavior
   **/
  void runBehavior() override;
};

#endif
/* empty_behavior_manager.hpp */
