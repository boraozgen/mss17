#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "systemc.h"

// C++ code needs to be inside the header file due to compiler limitations
// another (recommended way)
//
// sc_fifo_in input;
// sc_fifo_out adp_out[out_limit];

template<class T>
SC_MODULE(Adapter)
{
	sc_fifo<T> input;

	void bind(sc_fifo<T> &adp_out_) {
		adp_out[num_bound++] = &adp_out_;
	}

	void update() {
		while(1) {
			temp_read = input.read();
			for(int i=0; i<num_bound; i++) {
				adp_out[i]->write(temp_read);
			}
		}
	}

	SC_CTOR(Adapter) {
		SC_THREAD(update);
	}

	private:
		static const int out_limit = 5;
		int num_bound = 0;
		T temp_read;
		sc_fifo<T> *adp_out[out_limit];
};
#endif
