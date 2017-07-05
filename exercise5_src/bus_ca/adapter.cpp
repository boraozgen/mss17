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
      if (data != 0) {
        status = data;
        execution_trigger.notify();
      }
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
      data = status;
      break;
    default :
      cout << "Adapter: read from invalid address" << endl;
  }
}

void Adapter::execute_addition(void) {
  while(1) {

    unsigned data1, data2, result;

    wait(execution_trigger);

    cout << "DMA triggered" << " at " << sc_time_stamp() << endl;

    for( unsigned addr = 0; addr < block_size; addr++ )
    {
      cout <<  "Reading from " << start_addr1 + addr << " and " << start_addr2 + addr << ". Writing to " 
        << start_addr3 + addr << " at " << sc_time_stamp() << endl;
      initiator_port->read(start_addr1 + addr, data1, id);
      initiator_port->read(start_addr2 + addr, data2, id);
      x.write(data1);
      y.write(data2);
      wait(1, SC_NS); // Wait for adder to compute
      result = s.read();
      initiator_port->write(start_addr3 + addr, result, id);
    }

    status = 0;
  }
}