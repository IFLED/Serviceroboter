#include <ros/ros.h>

#include <tf/tf.h>

#include <moveit/move_group_interface/move_group.h>

#include <geometry_msgs/PoseStamped.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_msgs/Grasp.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>

#include <shape_tools/solid_primitive_dims.h>

#include "windows/Filename.h"


int main(int argc, char **argv)
{
    ros::init (argc, argv, "control");
    ros::NodeHandle nh;

    ros::Publisher display_publisher = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);

    ros::AsyncSpinner spinner(1);
    spinner.start();

    moveit::planning_interface::MoveGroup katana("manipulator");
    katana.setNamedTarget("home");
    katana.move();

    int temp;
    scanf("%d", &temp);

    const double STEP = 0.004;
    const double MAX = 1.05;

    
    ros::ServiceClient scan = nh.serviceClient<windows::Filename>("scan");
    windows::Filename srv;
/*    if (scan.call(srv))
    {
      ROS_INFO("Path: %s", srv.response.path.c_str());
    }
    else {
      ROS_INFO("asdf");
    }
*/
  
    for (int i = 0;; ++i) {
      
      geometry_msgs::PoseStamped msg = katana.getCurrentPose();
      geometry_msgs::Pose target_pose1;
      target_pose1.position.x = msg.pose.position.x;
      target_pose1.position.y = msg.pose.position.y;
      target_pose1.position.z = msg.pose.position.z + STEP;
      target_pose1.orientation.x = msg.pose.orientation.x;
      target_pose1.orientation.y = msg.pose.orientation.y;
      target_pose1.orientation.z = msg.pose.orientation.z;
      target_pose1.orientation.w = msg.pose.orientation.w;

      katana.setPoseTarget(target_pose1, "katana_gripper_tool_frame");
      moveit::planning_interface::MoveGroup::Plan my_plan2;
      bool success = katana.plan(my_plan2);
      if (success) {
        katana.move();
        if (scan.call(srv))
        {
          ROS_INFO("Path: %s", srv.response.path.c_str());
        }
        else {
          ROS_INFO("Fail");
        } 
      }
      
      ROS_INFO("%d z= %f", i, msg.pose.position.z);

      if (msg.pose.position.z > MAX) {
        break;
      }

      //sleep(1);
    }

    ros::spin();
  

}



