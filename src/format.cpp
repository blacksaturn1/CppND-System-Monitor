#include <string>
#include <sstream>

#include <iomanip>
#include <iostream>
#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
        //return std::to_string(seconds);
        long hours=seconds/3600;
        
        long minutes=(seconds-hours*3600)/60;
       
        long remainginseconds=(seconds-hours*3600-minutes*60);
        std::ostringstream out;
        out<<std::right<<std::setfill('0') << std::setw(2) <<hours<<
            ":"<<minutes<<":"<<remainginseconds;

        return out.str(); 
    }

string Format::kBtoMB(string kB) { 
        float mB=std::stof(kB)/1024.0;
        
        std::ostringstream out;
        out.precision(2);
        out<<std::right<<std::setw(8)<<std::fixed<<std::setprecision(2)<<mB;

        return out.str(); 
    }  