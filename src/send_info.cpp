#include "ros/ros.h"
#include "geometry_msgs/Pose.h"

float x,theta;
int flag=0;

void PosCallback(const geometry_msgs::Pose::ConstPtr& msg)
{
  x = msg.pose.position.x ;
  theta = msg.pose.orientation.z ;
}

int main(int argc, char **argv)
{
  float kp1,kp2, param_x, min_dist, param_theta;

  min_dist = std::atof(argv[1]);
  kp1 = std::atof(argv[2]);
  kp2 = std::atof(argv[3]);

  ros::init(argc, argv, "controls");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("controls_input", 1000, PoseCallback);

  std_msgs::Char com;
  std_msgs::Float32 pwm;
  ros::Publisher pub1 = n.advertise("command", &com);
  ros::Publisher pub2 = n.advertise("pwm", &pwm);

  param_x = kp1*x ;
  param_theta = kp2*theta ;

  while(n.ok()) {

  char charac;
  float value;
    if(x>min_dist && theta>(-0.15) && theta<0.15) {
      charac='F';
      value=param_x;

    }

    else if(theta>(0.15)) {
    charac='L';
    value=param_theta;
    }

    else if( theta<(-0.15)) {
    charac='R';
    value=param_theta;
    }

    else if(x<min_dist && flag==0) {
    value=100;
    for(int i=0;i<100;i++)
    {
    charac='R';
    }
    for(int i=0;i<10;i++)
    {
    charac='F';
    }
    flag=1;
    }

    else if(x<min_dist && flag==1) {
    value=100;
    for(int i=0;i<100;i++)
    {
    charac='L';
    }
    for(int i=0;i<10;i++)
    {
    charac='F';
    }
    flag=0;
    }

    com.data = charac;
    pub1.publish(&com);
    pwm.data = value;
    pub2.publish(&pwm);
  }

  ros::spinOnce();
  loop_rate.sleep();
  }

  return 0;
}
