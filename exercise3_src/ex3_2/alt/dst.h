#ifndef _DST_H_
#define _DST_H_

#include "systemc.h"
SC_MODULE(dst)
{
	sc_fifo_in<int> input;

	void behaviour();
	SC_CTOR(dst)
	{
		SC_METHOD(behaviour);
	}
};

#endif
