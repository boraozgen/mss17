#ifndef _TESTBENCH_H_
#define _TESTBENCH_H_

#include "systemc.h"
#include "adder.h"
#include "multiplier.h"
#include "decimator.h"
SC_MODULE(Testbench)
{ // a top level module; no ports

  sc_fifo<int> ch_a_in1, ch_a_in2, ch_a_out;  // channels
  sc_fifo<int> ch_m_in, ch_m_out;  // channels
  sc_fifo<int> ch_d_in, ch_d_out;  // channels

  Adder uut_A;      // Adder instance
  Multiplier uut_M; // Multiplier instance
  Decimator uut_D;  // Decimator instance

  void stim();      // stimuli process
  void check_A();   // checking process
  void check_M();   // checking process
  void check_D();   // checking process

  SC_CTOR(Testbench)
  : uut_A("uut_A"), // ch_a_in1("ch_a_in1")
	ch_a_in1(4), ch_a_in2(4), ch_a_out(3),
    uut_M("uut_M", 5), ch_m_in(4), ch_m_out(3),
    uut_D("uut_D"), ch_d_in(4), ch_d_out(3)
  {
    SC_THREAD(stim);       // without sensitivity

    SC_THREAD(check_A);
    uut_A.in1(ch_a_in1); // port x of uut_A bound to ch_a_in1
    uut_A.in2(ch_a_in2); // port y of uut_A bound to ch_a_in2
    uut_A.out(ch_a_out); // port s of uut_A bound to ch_a_out

    SC_THREAD(check_M);
    uut_M.in(ch_m_in);   // port x of uut_M bound to ch_m_in
    uut_M.out(ch_m_out); // port s of uut_M bound to ch_m_out

    SC_THREAD(check_D);
    uut_D.in(ch_d_in);   // port x of uut_D bound to ch_d_in
    uut_D.out(ch_d_out); // port s of uut_D bound to ch_d_out
  }
};

#endif

