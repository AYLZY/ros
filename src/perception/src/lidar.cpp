

#include <iostream>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>

void pointCloudCallback(const pcl::PointCloud<pcl::PointXYZ>::ConstPtr& cloud)
{
    pcl::visualization::CloudViewer viewer("PointCloud Viewer");
    viewer.showCloud(cloud);
    while (!viewer.wasStopped())
    {
    }
}

int main()
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());

    if (pcl::io::loadPCDFile<pcl::PointXYZ>("lidar_points.pcd", *cloud) == -1)
    {
        std::cerr << "Couldn't read file lidar_points.pcd" << std::endl;
        return -1;
    }

    pointCloudCallback(cloud);

    return 0;
}