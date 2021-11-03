#include "processor.h"
using std::string;
using std::vector;
// TODO: Return the aggregate CPU utilization

Processor::Processor(){
     vector<string> cpuInfo=LinuxParser::CpuUtilization();
     previousTotal_=stof(cpuInfo[0])+stof(cpuInfo[1])+stof(cpuInfo[2])+stof(cpuInfo[3]);
     previousIdle_=stof(cpuInfo[3]);
}
float Processor::Utilization() { 
    vector<string> cpuInfo=LinuxParser::CpuUtilization();
    total_=stof(cpuInfo[0])+stof(cpuInfo[1])+stof(cpuInfo[2])+stof(cpuInfo[3]);
    idle_=stof(cpuInfo[3]);
    // (100*( (total-prevtotal) - (idle-previdle) ) / (total-prevtotal)
    float totalDiff=total_-previousTotal_;
    if(0==totalDiff)return 0;

    float util=100*( (totalDiff) - (idle_-previousIdle_))/(totalDiff);
    previousTotal_=total_;
    previousIdle_=idle_;

    return util;//-previousTotal_;//100*( (total_-previousTotal_) - (idle_-previousIdle_))/(total_-previousTotal_); 

}