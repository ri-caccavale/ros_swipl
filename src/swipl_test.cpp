
#include <iostream>
#include "ros/ros.h"
#include "ros/package.h"
#include "SWIPL.h"



int main(int argc, char** argv) {
    
    ros::init(argc, argv, "swipl_test");

    std::string package_path = ros::package::getPath("ros_swipl");

    SWIPL swi(argc, argv);

    swi.consult(package_path + "/test.prolog");

    std::cout<<"QUERY: findall(A,anchestor(A,carl),List)"<<std::endl;
    std::string result = swi.query("findall(A,anchestor(A,carl),List)");

    std::cout<<"RESULT: "<<result<<std::endl;
    std::vector<std::string> result_list = SWIPL::list2vector( SWIPL::functor2vector(result)[3] );
    for(auto i=0; i<result_list.size(); i++){
    	std::cout<<i<<": "<<result_list[i]<<std::endl;
    }
        
    return 0;
}
