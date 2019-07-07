
# Home Service Robot
Project 5 of the Udacity Robotics Software Engineer Nanodegree Program.

# Getting Started
Clone the repository into a catkin workspace, make, and navigate to the scripts directory. From there, several scripts can be run to view the project.
```
$ catkin_make
$ cd src/scripts
```

# Test Slam
To run this program, in the scripts sub directory,
```
$ ./test_slam.sh
```
This script runs the turtlebot_myworld node to deploy a turtlebot in the environment, gmapping node to perform SLAM, view navigation node to observe the map in rviz and keyboard teleop node to manually control the robot with keyboard commands. 
The robot can be controlled to be moved around the environment in the keyboard teleop terminal window to perform SLAM, 

# Test Navigation
To run this program, in the scripts sub directory,
```
$ ./test_navigation.sh
```
This script runs the turtlebot_myworld node to deploy a turtlebot in the environment, an amcl node to localize the robot and a view navigation node to run rviz.
Set goals for the robot in the RViz window to direct the robot to the goals. 

# Pick Objects
To run this program, in the scripts sub directory,
```
$ ./pick_objects.sh
```
This script runs the turtlebot_myworld node, the AMCL node, RViz and the pick_objects node. 
The pick_objects node moves the robot to the pick up location, waits 5s and moves the robot to the dropoff location. 

# Add Markers
To run this program, in the scripts sub directory,
```
$ ./add_markers.sh
```
This script runs the turtlebot_myworld node, the AMCL node, RViz and the add_markers_test node. 
The add_markers_test file launches a marker at the pickup location, waits for 5 seconds, deletes the marker, waits 5 seconds, and launches the marker at the dropoff location.

# Home Service
To run this program, in the scripts sub directory,
```
$ ./home_service.sh
```
The home service node script runs a modified version of the add_markers node, combining the functionalities of the previous parts.
The robot localises itself in the map and travels to the pickup location, where a marker is waiting. When the robot reaches the pickup location, the marker vanishes. The robot then travels to the dropoff location, and the marker reappears again.
