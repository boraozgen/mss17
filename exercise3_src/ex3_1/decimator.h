#ifndef _DECIMATOR_H_
#define _DECIMATOR_H_

#include "systemc.h"
SC_MODULE(Decimator)
{
  // FIFO impl.
  sc_fifo_in<int> in;
  sc_fifo_out<int> out;
  int N;

  void decimate();
  SC_CTOR(Decimator)
   : N(10)
  {
    SC_THREAD(decimate);
  }
};
#endif
