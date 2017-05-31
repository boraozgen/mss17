#ifndef _SRC_H_
#define _SRC_H_

#include "systemc.h"
SC_MODULE(src)
{
	sc_fifo_out<int> output;

	void behaviour();
	SC_CTOR(src)
	{
		SC_THREAD(behaviour);
	}
};

#endif
