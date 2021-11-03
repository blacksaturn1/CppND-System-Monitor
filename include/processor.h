#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "linux_parser.h"
#include <string>
#include <vector>

class Processor {
 public:
  Processor();
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
    float previousTotal_;
    float previousIdle_;
    
    float total_;
    float idle_;

    
};

#endif