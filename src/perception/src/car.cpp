#include <iostream>
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <nav_msgs/Odometry.h>

void imuCallback(const sensor_msgs::Imu::ConstPtr& msg)
{
    // 打印imu数据
    std::cout << "IMU - Orientation: [" << msg->orientation.x << ", " << msg->orientation.y << ", " << msg->orientation.z << "], "
              << "Angular Velocity: [" << msg->angular_velocity.x << ", " << msg->angular_velocity.y << ", " << msg->angular_velocity.z << "], "
              << "Linear Acceleration: [" << msg->linear_acceleration.x << ", " << msg->linear_acceleration.y << ", " << msg->linear_acceleration.z << "]" << std::endl;
}

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    // 打印odom数据
    std::cout << "Odometry - Position: [" << msg->pose.pose.position.x << ", " << msg->pose.pose.position.y << ", " << msg->pose.pose.position.z << "], "
              << "Orientation: [" << msg->pose.pose.orientation.x << ", " << msg->pose.pose.orientation.y << ", " << msg->pose.pose.orientation.z << "]" << std::endl;
}

int main(int argc, char** argv)
{
    // 初始化ROS节点
    ros::init(argc, argv, "topic_subscriber");

    // 创建节点句柄
    ros::NodeHandle nh;

    // 创建两个订阅器，分别接收imu和odom话题的消息
    ros::Subscriber imuSub = nh.subscribe("/imu/data_raw", 1, imuCallback);
    ros::Subscriber odomSub = nh.subscribe("/odom", 1, odomCallback);

    // 开始接收和处理ROS消息
    ros::spin();

    return 0;
}