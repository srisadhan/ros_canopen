#include <std_msgs/Empty.h>
#include <gtest/gtest.h>
#include <ros/ros.h>

void assign(std_msgs::Empty::ConstPtr &dest, std_msgs::Empty::ConstPtr src) { dest = src; }

TEST(TopicToSocketCANTest, Something)
{
  ros::NodeHandle nh;

  ROS_INFO("Blub"); // can be moved down

  std_msgs::Empty::ConstPtr received;
  ros::Subscriber subscriber = nh.subscribe<std_msgs::Empty>("sent_messages", 1, boost::bind(assign, boost::ref(received), _1));

  ros::Publisher publisher_ = nh.advertise<std_msgs::Empty>("sent_messages", 1); // must come after subscriber
}

TEST(TopicToSocketCANTest, SomethingElse)
{

  ros::NodeHandle nh;

  ros::Publisher publisher_ = nh.advertise<std_msgs::Empty>("sent_messages", 1);

  std_msgs::Empty::ConstPtr received;
  ros::Subscriber subscriber = nh.subscribe<std_msgs::Empty>("sent_messages", 1, boost::bind(assign, boost::ref(received), _1));

  std_msgs::Empty msg;
  publisher_.publish(msg);

  // give some time for the interface some time to process the message
  ros::WallDuration(1.0).sleep();
  EXPECT_FALSE(received);
  ros::spinOnce();
  EXPECT_TRUE(received);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_to_topic");
  ros::WallDuration(1.0).sleep();
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
