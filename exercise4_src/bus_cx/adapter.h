#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "bus_if.h"

#define ADP_START_ADDR	1024
#define ADP_MEM_SZ		3

#define ADDER_INPUT1    1024
#define ADDER_INPUT2    1025
#define ADDER_OUTPUT    1026

class Adapter : public sc_module, public bus_if
{
public:
  sc_export<bus_if> target_export;
  sc_out<int> x;
  sc_out<int> y;
  sc_in<int> s;
  void write( unsigned addr, unsigned  data );
  void read(  unsigned addr, unsigned &data );
  void test();
  unsigned start, sz;
  unsigned *mem;
  SC_HAS_PROCESS(Adapter);
  Adapter( sc_module_name mn )
  : sc_module(mn)
  {
	 // SC_THREAD(test);
    target_export.bind(*this);
    start = ADP_START_ADDR;
	 sz = ADP_MEM_SZ;
    mem = new unsigned[sz];
  }
  ~Adapter() { delete[] mem; }
};

#endif
