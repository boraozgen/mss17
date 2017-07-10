#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "bus_if.h"

class Adapter : public sc_module, public bus_if
{
public:
  sc_port<ext_bus_if,1> initiator_port;
  sc_out<int> x;
  sc_out<int> y;
  sc_in<int>  s;

	unsigned id; // ID of this adapter module
  unsigned start_addr1; // addr. input 1
  unsigned start_addr2; // addr. input 2
  unsigned start_addr3; // addr. output
  unsigned block_size;  // # additions to be performed
  unsigned status;			// status of the operations

	sc_event add_event; // used to trigger the add operation

  void write( unsigned addr, unsigned  data );
  void read(  unsigned addr, unsigned &data );
  void add_prc();

  SC_HAS_PROCESS(Adapter);
  Adapter(sc_module_name mn, unsigned id = 0) : sc_module(mn)
  {
		SC_THREAD(add_prc); // sensitive to add_event
    this->id = id;
    return; // alternative: export the bus_if here
  }

};

#endif
