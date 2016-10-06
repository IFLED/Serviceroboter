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

/*
ros::Publisher pub_co;
ros::Publisher pub_aco;
ros::Publisher grasps_marker;

ros::Subscriber sub_point;

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


    geometry_msgs::PoseStamped msg = katana.getCurrentPose();

    ROS_INFO("%s", msg.header.frame_id.c_str());
    ROS_INFO("%f %f %f", msg.pose.position.x, msg.pose.position.y, msg.pose.position.z);
    ROS_INFO("%f %f %f %f", msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w);
    ROS_INFO("---");


    geometry_msgs::Pose target_pose1;
    target_pose1.position.x = msg.pose.position.x;
    target_pose1.position.y = msg.pose.position.y;
    target_pose1.position.z = msg.pose.position.z+0.00;
    tf::Quaternion qq = tf::createQuaternionFromRPY(0, 0, 0);
   // target_pose1.orientation.x = (double)(qq.getX());
    target_pose1.orientation.y = (double)qq.getY();
    target_pose1.orientation.z = (double)qq.getZ();
   // target_pose1.orientation.w = (double)qq.getW();
    
    target_pose1.orientation.x = msg.pose.orientation.x;
    target_pose1.orientation.y = msg.pose.orientation.y;
    target_pose1.orientation.z = msg.pose.orientation.z;
    target_pose1.orientation.w = msg.pose.orientation.w;

    ROS_INFO("%f %f %f %f", qq.getX(), qq.getY(), qq.getZ(), qq.getW());

//    
    geometry_msgs::Pose target_pose2;
    target_pose2.position.x = msg.pose.position.x;
    target_pose2.position.y = msg.pose.position.y;
    target_pose2.position.z = msg.pose.position.z+0.05;
    target_pose2.orientation.x = msg.pose.position.x;
    target_pose2.orientation.y = msg.pose.position.y;
    target_pose2.orientation.z = msg.pose.orientation.z;
    target_pose2.orientation.w = msg.pose.orientation.w;

    katana.setPoseTarget(target_pose2, "tip_link");
    moveit::planning_interface::MoveGroup::Plan my_plan;
    bool success = katana.plan(my_plan);
    katana.move();
//
    katana.setPoseTarget(target_pose1, "katana_gripper_tool_frame");
    moveit::planning_interface::MoveGroup::Plan my_plan2;
    bool success = katana.plan(my_plan2);
    katana.move();

    msg = katana.getCurrentPose("tip_link");
    ROS_INFO("%s", msg.header.frame_id.c_str());
    ROS_INFO("%f %f %f", msg.pose.position.x, msg.pose.position.y, msg.pose.position.z);
    ROS_INFO("%f %f %f %f", msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w);

    tf::Quaternion q(msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w);
    tf::Matrix3x3 m(q);
    double roll, pitch, yaw;
    m.getRPY(roll, pitch, yaw);

    ROS_INFO("RPY: %f %f %f", roll, pitch, yaw);

    ROS_INFO("---");

    std::vector<double> group_variable_values;
    katana.getCurrentState()->copyJointGroupPositions(katana.getCurrentState()->getRobotModel()->getJointModelGroup(katana.getName()), group_variable_values);
    for (int i = 0; i < group_variable_values.size(); ++i) {
      ROS_INFO("valueee %f", group_variable_values[i]);
    }

    int temp;
    scanf("%d", &temp);
  
    for (int i = 0; i < 100; ++i) {
      
      geometry_msgs::PoseStamped msg = katana.getCurrentPose();
      geometry_msgs::Pose target_pose1;
      target_pose1.position.x = msg.pose.position.x;
      target_pose1.position.y = msg.pose.position.y;
      target_pose1.position.z = msg.pose.position.z+0.001;
      target_pose1.orientation.x = msg.pose.orientation.x;
      target_pose1.orientation.y = msg.pose.orientation.y;
      target_pose1.orientation.z = msg.pose.orientation.z;
      target_pose1.orientation.w = msg.pose.orientation.w;

      katana.setPoseTarget(target_pose1, "katana_gripper_tool_frame");
      moveit::planning_interface::MoveGroup::Plan my_plan2;
      bool success = katana.plan(my_plan2);
      katana.move();
      
      ROS_INFO("%d", i);
      //sleep(1);
    }

    ros::spin();
  

}
*/


/*


    moveit::planning_interface::MoveGroup::Plan my_plan;

    std::vector<double> group_variable_values;
    katana.getCurrentState()->copyJointGroupPositions(katana.getCurrentState()->getRobotModel()->getJointModelGroup(katana.getName()), group_variable_values);
    for (int i = 0; i < group_variable_values.size(); ++i) {
      ROS_INFO("valueee %f", group_variable_values[i]);
    }
    group_variable_values[0] = -1.0;
    katana.setJointValueTarget(group_variable_values);
    bool success = katana.plan(my_plan);

    if (success) {
      katana.move();
    }
*/
