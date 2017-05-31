#include "systemc.h"
#include "src.h"
#include "dst.h"
#include "adder.h"
#include "multiplier.h"
#include "decimator.h"
#include "adapter.h"
#include "testbench.h"

int sc_main(int argc, char *argv[])  // cf. C++ main()
{
	
	Testbench tb("tb");
	sc_start();
	cout << endl <<"simulation finished" << endl;
	return 0;
}



