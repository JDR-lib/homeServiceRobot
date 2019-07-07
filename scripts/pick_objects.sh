#!/bin/sh
xterm  -e  "cd ../.. && source devel/setup.bash && roslaunch my_robot turtlebot_myworld.launch" &
sleep 15
xterm  -e  "cd ../.. && source devel/setup.bash && roslaunch my_robot turtlebot_amcl.launch" & 
sleep 10
xterm  -e  "cd ../.. && source devel/setup.bash && roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 10
xterm  -e  "cd ../.. && source devel/setup.bash && rosrun pick_objects pick_objects"


