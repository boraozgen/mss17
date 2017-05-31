#include "testbench.h"
void Testbench::stim()  // SC_THREAD
{
  int arr1[4] = {3, 7, 8, 8};
  int arr2[4] = {4, 0, -4, -4};

  for (int i=0; i<4; i++) {
    ch_a_in1.write(arr1[i]); ch_a_in2.write(arr2[i]);
    cout << "stim: in1 = " << arr1[i];
    cout << ", in2 = " << arr2[i] << endl;
  }

  for (int i=1; i<5; i++) {
    ch_m_in.write(i);
    cout << "stim: in = " << i << endl;
  }

  for (int i=1; i<11; i++) {
    ch_d_in.write(i);
    cout << "stim: in = " << i << endl;
  }
}
void Testbench::check_A() // SC_THREAD
{
  while(1) {
    cout << "check_A: in1 + in2 = " << ch_a_out.read() << endl;
    wait(10, SC_NS);
  }
}
void Testbench::check_M() // SC_THREAD
{
  while(1) {
    cout << "check_M: in * K = " << ch_m_out.read() << endl;
    wait(10, SC_NS);
  }
}
void Testbench::check_D() // SC_THREAD
{
  while(1) {
    cout << "check_D: in = " << ch_d_out.read() << endl;
    wait(10, SC_NS);
  }
}
