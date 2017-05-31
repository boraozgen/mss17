// file main.cpp
#include "systemc.h"
#include "testbench.h"
int sc_main(int argc, char *argv[])  // cf. C++ main()
{
  Testbench tb("tb");
  sc_start();
  cout << "simulation finished" << endl;
  return 0;
}
