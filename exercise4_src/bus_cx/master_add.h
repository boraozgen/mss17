#ifndef _MASTER_ADD_H_
#define _MASTER_ADD_H_

#include "bus_if.h"

#define ADDER_INPUT1    1024
#define ADDER_INPUT2    1025
#define ADDER_OUTPUT    1026

#define SUM_RAM_START   64

#define RAM_OFFSET      16

SC_MODULE( MasterAdd )
{
  sc_port<bus_if,1> initiator_port;
  void action();
  unsigned start, end, id;
  SC_HAS_PROCESS(MasterAdd);
  MasterAdd( sc_module_name mn, unsigned start_addr, unsigned end_addr, unsigned id = 0 )
  : sc_module( mn )
  {
    SC_THREAD(action);
    this->id = id;
    start = start_addr;
    end = end_addr;
  }
};

#endif
