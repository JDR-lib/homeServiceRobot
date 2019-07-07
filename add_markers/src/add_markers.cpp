#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <math.h>

float pickupX = 0.0;
float pickupY = 1.0;
float dropoffX = 0.0;
float dropoffY = 2.0;

//robot odom positions
float robotX;
float robotY;
//initially show marker at pickup zone
//hide marker once robot reaches pickup zone
//wait 5s to simulate pickup
//show marker at dropoff zone once robot reaches it
bool pickedUp = false;
bool atPickup = false;
bool atDropoff = false;

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
{
    robotX = msg->pose.pose.position.x;
    robotY = msg->pose.pose.position.y;
    //ROS_INFO("xodom: %f ||||| yodom: %f",robotX, robotY);


    float pickupRadius = sqrt(pow(fabs(robotX - pickupX), 2) + pow(fabs(robotY - pickupY), 2));
    float dropoffRadius = sqrt(pow(fabs(robotX - dropoffX), 2) + pow(fabs(robotY - dropoffY), 2));

    if (pickupRadius < 0.3)
    {
      atPickup = true;
    }

    if (dropoffRadius < 0.3)
    {
      atDropoff = true;
    }

}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odom_call = n.subscribe("odom", 10, odomCallback);
  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = pickupX;
    marker.pose.position.y = pickupY;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 1.0;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 1.0f;
    marker.color.g = 0.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();
    while(ros::ok())
    {
      // Publish the marker
      while (marker_pub.getNumSubscribers() < 1)
      {
        if (!ros::ok())
        {
          return 0;
        }
        ROS_WARN_ONCE("Please create a subscriber to the marker");
        sleep(1);
      }

      if (pickedUp == false)
      {
        marker_pub.publish(marker);
        pickedUp == true;
      }

      if (atPickup == true)
      {
        marker.action = visualization_msgs::Marker::DELETE;
        marker_pub.publish(marker);
      }

      if (atDropoff == true)
      {
        marker.pose.position.x = dropoffX;
        marker.pose.position.y = dropoffY;      
        atPickup == false;
        marker.action = visualization_msgs::Marker::ADD;
        marker_pub.publish(marker);
      }
      ros::spinOnce();
    }
    //ros::spinOnce();
  
}


// #include <ros/ros.h>
// #include <visualization_msgs/Marker.h>
// #include <nav_msgs/Odometry.h>
// #include <math.h>


// float pickupX = 0.0;
// float pickupY = 1.0;
// float dropoffX = 0.0;
// float dropoffY = 2.0;

// //robot odom positions
// float robotX;
// float robotY;
// //initially show marker at pickup zone
// //hide marker once robot reaches pickup zone
// //wait 5s to simulate pickup
// //show marker at dropoff zone once robot reaches it
// bool pickedUp = false;
// bool atPickup = false;
// bool atDropOff = false;

// void odomCallback(const nav_msgs::Odometry::ConstPtr& msg)
// {
//     robotX = msg->pose.pose.position.x;
//     robotY = msg->pose.pose.position.y;
//     //ROS_INFO("xodom: %f ||||| yodom: %f",robotX, robotY);


//     float pickupRadius = sqrt(pow(fabs(robotX - pickupX), 2) + pow(fabs(robotY - pickupY), 2));
//     float dropoffRadius = sqrt(pow(fabs(robotX - dropoffX), 2) + pow(fabs(robotY - dropoffY), 2));

//     if (pickupRadius < 0.3)
//     {
//       atPickup = true;
//     }

//     if (dropoffRadius < 0.3)
//     {
//       atDropOff = true;
//     }

// }


// int main( int argc, char** argv)
// {
//   ros::init(argc, argv, "add_markers");
//   ros::NodeHandle n;

//   ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 0);
//   ros::Subscriber odom_call = n.subscribe("odom", 1, odomCallback);

//   visualization_msgs::Marker marker;
//   // Set the frame ID and timestamp.  See the TF tutorials for information on these.
//   marker.header.frame_id = "map";
//   marker.header.stamp = ros::Time::now();

//   // Set the namespace and id for this marker.  This serves to create a unique ID
//   // Any marker sent with the same namespace and id will overwrite the old one
//   marker.ns = "cube";
//   marker.id = 0;

//   // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
//   marker.type = visualization_msgs::Marker::CUBE;

//   // Set the scale of the marker -- 1x1x1 here means 1m on a side
//   marker.scale.x = 0.5;
//   marker.scale.y = 0.5;
//   marker.scale.z = 1.0;

//   // Set the color -- be sure to set alpha to something non-zero!
//   marker.color.r = 1.0f;
//   marker.color.g = 0.0f;
//   marker.color.b = 0.0f;
//   marker.color.a = 1.0;

//   marker.lifetime = ros::Duration();


//       // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
//   marker.pose.position.x = pickupX;
//   marker.pose.position.y = pickupY;
//   marker.pose.position.z = 0;

//   marker.action = visualization_msgs::Marker::ADD;
//   marker_pub.publish(marker);

//   if (pickedUp == false)
//   {
//       for (int i = 0; i < 5; i++)
//       {
          
//           pickedUp = true;

//           ROS_INFO("picked up");
//       }

//   }

//   if (atPickup == true)
//   {
//       for (int i = 0; i < 5; i++)
//       {  
//         marker.action = visualization_msgs::Marker::DELETE;
//         marker_pub.publish(marker);
//         ROS_INFO("at pick up");
//       }
//   }

//   else if (atDropOff == true)
//   {
//       marker.pose.position.x = dropoffX;
//       marker.pose.position.y = dropoffY;
//       marker.action = visualization_msgs::Marker::ADD;
//       marker_pub.publish(marker);
//       ROS_INFO("at drop off");
//   }

//   ros::spin();

// }