#ifndef _DECIMATOR_H_
#define _DECIMATOR_H_

#include "systemc.h"
SC_MODULE(Decimator)
{
  sc_fifo_in<int> in;
  sc_fifo_out<int> out;
  int N;

  void decimate();

  SC_HAS_PROCESS(Decimator);
  Decimator(sc_module_name name_, int counter_) :
    sc_module(name_), N(counter_)
  {
    SC_THREAD(decimate);
  }
};
#endif
