
#include <iostream>

#include "ros/ros.h"
#include "ros/package.h"
#include "SWIPL.h"

#include <signal.h>

//services:
#include "ros_swipl/query.h"
#include "ros_swipl/consult.h"


class ros_swipl_node {
public:
    ros_swipl_node(int &argc, char **argv){
        ros_package_path = ros::package::getPath("ros_swipl"); //just in case
        ss_query=nh.advertiseService("/ros_swipl/query", &ros_swipl_node::service_query, this);
        ss_consult=nh.advertiseService("/ros_swipl/consult", &ros_swipl_node::service_consult, this);

        swi = new SWIPL(argc, argv);
    }

    ~ros_swipl_node(){
        delete swi;

        std::cout<<"ROS_SWIPL exited"<<std::endl;
    }

    //services: 
    bool service_consult(ros_swipl::consult::Request  &req, ros_swipl::consult::Response &res){
        res.result = swi->consult(req.filepath);
        return true;
    }

    bool service_query(ros_swipl::query::Request  &req, ros_swipl::query::Response &res){
        res.result = swi->query(req.query);
        return true;
    }

private:
    ros::NodeHandle nh;
    ros::ServiceServer ss_query;
    ros::ServiceServer ss_consult;

    std::string ros_package_path;

    SWIPL *swi;
};


int main(int argc, char** argv) {
    
    ros::init(argc, argv, "ros_swipl");

    ros_swipl_node *node = new ros_swipl_node(argc, argv);
    
    std::cout<<"ROS_SWIPL started"<<std::endl;

    ros::spin();

    delete node;
        
    return 0;
}
