cmake_minimum_required(VERSION 2.8.3)
project(empty_behavior_manager)

add_compile_options(-std=c++11 -g -O0)

find_package(catkin REQUIRED
  COMPONENTS
    behavior_manager
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  INCLUDE_DIRS include
  LIBRARIES
    ${PROJECT_NAME}
  CATKIN_DEPENDS
    behavior_manager
)

###########
## Build ##
###########

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## EmptyBehaviorManager Library
#add_library(${PROJECT_NAME}
#  src/empty_behavior_manager.cpp
#)
#add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#target_link_libraries(${PROJECT_NAME}
#  behavior_manager
#  ${catkin_LIBRARIES}
#)

## Test Node
#add_executable(${PROJECT_NAME}_node
#  src/empty_behavior_manager_node.cpp
#  src/empty_behavior_manager.cpp
#)
#set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME ${PROJECT_NAME}_node PREFIX "")
#add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
#target_link_libraries(${PROJECT_NAME}_node
#  behavior_manager
#  ${catkin_LIBRARIES}
#)

#############
## Install ##
#############

#install(TARGETS ${PROJECT_NAME}
#  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
  PATTERN ".svn" EXCLUDE
)

