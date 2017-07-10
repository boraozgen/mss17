#include "adapter.h"

void Adapter::write(unsigned addr, unsigned  data) {
  switch(addr) {
  case 1024 :
    start_addr1 = data;
    break;
  case 1025 :
    start_addr2 = data;
    break;
  case 1026 :
    start_addr3 = data;
    break;
  case 1027 :
    block_size = data;
    break;
  case 1028 :
	 status = data; 
	 // start the addition
    if (data != 0) { add_event.notify(); }
    break;
  default :
    cout << "Adapter: write to invalid address" << endl;
  }
}

void Adapter::read( unsigned addr, unsigned &data) {
  switch(addr) {
  case 1024 :
    data = start_addr1;
    break;
  case 1025 :
    data = start_addr2;
    break;
  case 1026 :
    data = start_addr3;
    break;
  case 1027 :
    data = block_size;
    break;
  case 1028 :
		data = 0; // if the addition is finished
		// data = 1; if the addition is not finished
    break;
  default :
    cout << "Adapter: read from invalid address" << endl;
  }
}

void Adapter::add_prc()
{
	unsigned data1, data2, data3;
	while(1) {
		wait(add_event);
		for (unsigned i=0; i<block_size; i++) {
			cout <<  "Reading from "	<< start_addr1 + i
				<< " and "					<< start_addr2 + i 
				<< ". Writing to "		<< start_addr3 + i
				<< " at " << sc_time_stamp() << endl;
			initiator_port->read(start_addr1 + i, data1, id);
			initiator_port->read(start_addr2 + i, data2, id);
			x.write(data1);
			y.write(data2);
			wait(1, SC_NS); // wait for adder to finish
			data3 = s.read();
			initiator_port->write(start_addr3 + i, data3, id);
		}
		status = 0;
	}
}
