#ifndef __WATCH_H_
#define __WATCH_H_
#include "systemc.h"
#include "counter.h"

SC_MODULE(Watch) {
	sc_in<bool> clk;
	Counter sec, min, hour;
	sc_event next_minute, next_hour;

	void inc_sec();
	void inc_min();
	void inc_hour();
	void write_time();

	SC_CTOR(Watch)
		: sec(60), min(60), hour(24)
	{
		SC_METHOD(inc_sec);
		sensitive << clk.pos();
		dont_initialize();

		SC_METHOD(inc_min);
		sensitive << next_minute;
		dont_initialize();

		SC_METHOD(inc_hour);
		sensitive << next_hour;
		dont_initialize();

		SC_METHOD(write_time);
		sensitive << clk.neg();
	}

};
#endif
