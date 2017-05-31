#ifndef _TESTBENCH_H_
#define _TESTBENCH_H_

#include "systemc.h"
#include "src.h"
#include "dst.h"
#include "adder.h"
#include "multiplier.h"
#include "decimator.h"
#include "adapter.h"

// tracing # tokens
// sc_fifo<> arc; sc_signal<int> arcsize;
// arcsize = arc.size(); -> in an SC_METHOD sensitive to arc.value_changed()
// sc_trace(tf, arcsize, "arcsize"); -> tf is a pointer to a trace file

SC_MODULE(Testbench) {
	sc_fifo<int> arc[12];
	Adapter<int> data_src_adp;
	Adapter<int> ADD_4_adp;

	src			data_src;
	dst			data_dst;
	Adder 		ADD_1, ADD_2, ADD_3, ADD_4;
	Multiplier	MUL_1, MUL_2;
	Decimator	DEC;
	
	void init() {
		arc[1].write(0);
		arc[2].write(0); arc[2].write(0);
		arc[6].write(0); arc[6].write(0);
		arc[8].write(0);
	}

	SC_CTOR(Testbench) :
		data_src_adp("data_src_adp"), ADD_4_adp("ADD_4_adp"),
		data_src("data_src"), data_dst("data_dst"),
		ADD_1("ADD_1"), ADD_2("ADD_2"), ADD_3("ADD_3"), ADD_4("ADD_4"),
		MUL_1("MUL_1", -3), MUL_2("MUL_2", -2),
		DEC("DEC", 10)
	{
		SC_THREAD(init);

		data_src.output(data_src_adp.input);
		data_src_adp.bind(arc[0]);
		data_src_adp.bind(arc[1]);
		data_src_adp.bind(arc[2]);

		ADD_1.in1(arc[0]);
		ADD_1.in2(arc[1]);
		ADD_1.out(arc[3]);
		
		ADD_2.in1(arc[2]);
		ADD_2.in2(arc[3]);
		ADD_2.out(arc[4]);
		
		ADD_3.in1(arc[4]);
		ADD_3.in2(arc[7]);
		ADD_3.out(arc[5]);
		
		ADD_4.in1(arc[5]);
		ADD_4.in2(arc[9]);
		ADD_4.out(ADD_4_adp.input);
		ADD_4_adp.bind(arc[6]);
		ADD_4_adp.bind(arc[8]);
		ADD_4_adp.bind(arc[10]);

		MUL_1.in(arc[6]);
		MUL_1.out(arc[7]);
		
		MUL_2.in(arc[8]);
		MUL_2.out(arc[9]);
		
		DEC.in(arc[10]);
		DEC.out(arc[11]);
		
		data_dst.input(arc[11]);
	}
};

#endif
