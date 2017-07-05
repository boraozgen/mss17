#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "bus_if.h"

class Adapter : public sc_module, public bus_if
{
public:
  sc_out<int> x;
  sc_out<int> y;
  sc_in<int>  s;

  // Adapter master port
  sc_port<ext_bus_if,1> initiator_port;

  // New attributes
  unsigned start_addr1;
  unsigned start_addr2;
  unsigned start_addr3;
  unsigned block_size;
  unsigned status;

  // Master ID
  unsigned id; 

  void execute_addition(void);

  // Event to trigger execution
  sc_event execution_trigger;

  void write( unsigned addr, unsigned  data );
  void read(  unsigned addr, unsigned &data );

  SC_HAS_PROCESS(Adapter);

  Adapter( sc_module_name mn, unsigned id = 0 ) : sc_module(mn)
  {
    SC_THREAD(execute_addition);
  }

};

#endif
