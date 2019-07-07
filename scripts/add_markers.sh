#!/bin/sh
xterm  -e  "cd ../.. && source devel/setup.bash && roslaunch my_robot turtlebot_myworld.launch" &
sleep 10
xterm  -e  "cd ../.. && source devel/setup.bash && roslaunch my_robot turtlebot_amcl.launch" & 
sleep 10
xterm  -e  "cd ../.. && source devel/setup.bash && roslaunch add_markers home_service.launch" &
sleep 10
xterm  -e  "cd ../.. && source devel/setup.bash && rosrun add_markers add_markers_test"
