# ros_swipl
Simple ROS node wrapping the SWI-Prolog engine. The node is based on a SWIPL wrapper class that can also be used standalone as simple C++ interface with SWI. 

## Installation requirements
Install and configure ROS from [here](http://wiki.ros.org/ROS/Installation)

Install SWI-Prolog from repository:
```
sudo apt-add-repository ppa:swi-prolog/stable
sudo apt-get update
sudo apt-get install swi-prolog
```

## Running instructions
Run the test node using the following command:
```
rosrun ros_swipl swipl_test
```
