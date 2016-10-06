#include "ros/ros.h"
#include "windows/Filename.h"
#include <fstream>

#include <stdio.h>
#include <stdlib.h>
#include <string>

bool scan(windows::Filename::Request  &req,
          windows::Filename::Response &res)
{
  ROS_INFO("Request to scan");

  std::ofstream fout("/home/samba/shared/project/scan");
  fout.close();

  int code = -1;
  while (code != 256) {
    code = system("[ -f '/home/samba/shared/project/scan' ] && ls /asdf > /dev/null");
    sleep(0.01);
    ROS_INFO("%d", code);
  }
  code = -1;


  while (code != 0) {
    code = system("cp /home/samba/shared/project/Input/* /home/samba/shared/project/windows/tmp");
    sleep(0.01);
  }

  system("ls /home/samba/shared/project/windows/tmp | cut -d'.' -f 1| sort -u > /home/samba/shared/project/windows/filename");

  system("mv /home/samba/shared/project/windows/tmp/* /home/samba/shared/project/images");

  std::ifstream fin("/home/samba/shared/project/windows/filename");
  std::string filename;
  fin >> filename;
  fin.close();

  char path[1000];
  sprintf(path, "/home/samba/shared/project/images/%s",  filename.c_str());
  res.path = path;
  ROS_INFO("sending back response: [%s]", res.path.c_str());
  return true;
}

bool stop(windows::Filename::Request  &req,
          windows::Filename::Response &res)
{
  ROS_INFO("Request to stop");

  std::ofstream fout("/home/samba/shared/project/stop");
  fout.close();

  res.path = "ok";
  ROS_INFO("sending back response: [%s]", res.path.c_str());
  return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "scanner");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("scan", scan);
    ros::ServiceServer service2 = n.advertiseService("stop", stop);
    ROS_INFO("Ready to scan");
    ros::spin();

    return 0;
}
