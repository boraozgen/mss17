#include "systemc.h"
#include "watch.h"
#include "counter.h"

int sc_main(int argc, char *argv[]) {
	sc_clock clk("clk", 1, SC_SEC, 0.5, 0, SC_NS);
	Watch watch("watch");
	watch.clk(clk);

	// run a bit more than a day
	int run_time = 3600*24 + 10;
	if (argc == 2) {
		switch(*argv[1]) {
			case 'm':
			case 'M':
				run_time = 60 + 10;
				break;
			case 'h':
			case 'H':
				run_time = 3600 + 10;
				break;
			case 'd':
			case 'D':
				run_time = 3600*24 + 10;
				break;
			default:
				run_time = 3600*24 + 10;
				break;
		}
	}

	sc_start(run_time, SC_SEC);
	cout << "Simulation finished" << endl;

	return 0;
}
