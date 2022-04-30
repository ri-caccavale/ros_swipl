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

## Running the test node
Run the test node using the following command:
```
rosrun ros_swipl swipl_test
```
it will execute a simple static query on the test database.

## Running the ROS node
Run the ROS node using the following command:
```
rosrun ros_swipl ros_swipl
```
After that, the followin services will be available:
```
/ros_swipl/consult	# consult the database specified in "filepath"
/ros_swipl/query	# unify the predicate spefied in "query"
```
You can try a command-line service call:
```
rosservice call /ros_swipl/query '{query: "arg(1,foo(arg1),X)"}'
```
The variable X will be unified with arg1.

## Notes:
The ctrl+c signal to shutdown the node is not working
