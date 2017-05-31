#ifndef _ADAPTER_H_
#define _ADAPTER_H_

#include "systemc.h"

// C++ code needs to be inside the header file due to compiler limitations
//boraya anlat

template<class T, int N>
SC_MODULE(Adapter)
{
	sc_fifo_in<T>  input;
	sc_fifo_out<T> out[N];

	void update() {
		while(1) {
			temp_read = input.read();
			for(int i=0; i<N; i++) {
				out[i].write(temp_read);
			}
		}
	}

	SC_CTOR(Adapter) {
		SC_THREAD(update);
	}

	private:
		T temp_read;
};
#endif
