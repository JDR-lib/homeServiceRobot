#!/bin/sh
xterm  -e  "cd ../.. && source devel/setup.bash && roslaunch my_robot turtlebot_myworld.launch" &
sleep 10
xterm  -e  "cd ../.. && source devel/setup.bash && roslaunch my_robot turtlebot_amcl.launch" & 
sleep 5
xterm  -e  "cd ../.. && source devel/setup.bash && roslaunch turtlebot_rviz_launchers view_navigation.launch"