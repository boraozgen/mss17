#ifndef _ADDER_H_
#define _ADDER_H_

#include "systemc.h"
SC_MODULE(Adder)
{
  sc_fifo_in<int> in1;
  sc_fifo_in<int> in2;
  sc_fifo_out<int> out;

  void add();
  SC_CTOR(Adder)
  {
    SC_THREAD(add);
  }

};
#endif
