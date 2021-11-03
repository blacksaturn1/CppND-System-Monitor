#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "format.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid){//,float cpu,string command,string ram,string user,long uptime){
    pid_=pid;
    long systemJiffies=LinuxParser::Jiffies();
    long activeJiffies=LinuxParser::ActiveJiffies();
    long idleJiffies=LinuxParser::IdleJiffies();
    long pidJiffies=LinuxParser::ActiveJiffies(pid_);
    string uid=LinuxParser::Uid(pid_);
    //cpuUtilization_=cpu;
    command_=LinuxParser::Command(pid_);
    ram_=Format::kBtoMB(LinuxParser::Ram(pid_));
    user_=LinuxParser::User(pid_);
    //upTime_=uptime;
    
}
// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { return cpuUtilization_; }

// TODO: Return the command that generated this process
string Process::Command() { return command_; }

// TODO: Return this process's memory utilization
string Process::Ram() { return ram_; }

// TODO: Return the user (name) that generated this process
string Process::User() { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return upTime_; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
    
    return this->cpuUtilization_<a.cpuUtilization_; 
    
}