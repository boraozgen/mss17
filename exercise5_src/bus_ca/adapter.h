#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "bus_if.h"

class Adapter : public sc_module, public bus_if
{
public:
  sc_out<int> x;
  sc_out<int> y;
  sc_in<int>  s;

  void write( unsigned addr, unsigned  data );
  void read(  unsigned addr, unsigned &data );

  Adapter( sc_module_name mn ) : sc_module(mn)
  {
    return; // alternative: export the bus_if here
  }

};

#endif
