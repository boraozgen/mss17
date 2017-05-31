#ifndef _MULTIPLIER_H_
#define _MULTIPLIER_H_

#include "systemc.h"
SC_MODULE(Multiplier)
{
  sc_fifo_in<int> in;
  sc_fifo_out<int> out;
  int K;

  void multiply();

  SC_HAS_PROCESS(Multiplier);
  Multiplier(sc_module_name name_, int factor_) :
    sc_module(name_), K(factor_)
  {
    SC_THREAD(multiply);
  }
};
#endif
