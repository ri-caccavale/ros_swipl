/*
 * File:   SWIPL.h
 * Author: ri-caccavale
 *
 * Created on 29 april 2022
 */

#ifndef SWI_wrapper_H
#define SWI_wrapper_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    // std::replace
#include <sstream>      // std::stringstream
#include <unordered_map>

#include <SWI-cpp.h>
#include <SWI-Prolog.h>

/*
* SWIPL wrapper class for SWI Prolog 
*/
class SWIPL {
public:

    SWIPL();

    SWIPL(int &, char **);

    ~SWIPL();

    static std::vector<std::string> functor2vector(std::string);

    static std::vector<std::string> list2vector(std::string);
    
    bool consult(std::string);
    
    std::string query(std::string);
    
private:
    
    PlTerm string2term(std::string str, std::unordered_map<std::string, PlTerm> &);
    
    std::string prolog_path;
    
    PlEngine *swi_engine;
    
};



#endif	/* SWI_wrapper_H */

