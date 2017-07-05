#include "master_add.h"

void MasterAdd::action()
{
  unsigned data;
  wait(1000, SC_NS);

  cout << "Adding master begins..." << endl;

  for(unsigned addr = start; addr <= end; addr++) {
    // Read from first RAM
    initiator_port->read(addr, data);
    cout << name() << " read(" << addr << ", " << data << ")" 
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);
    // Write to first adder input
    initiator_port->write(ADDER_INPUT1, data);
    cout << name() << " write(" << addr << ", " << data << ")" 
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);

    // Read from second RAM
    initiator_port->read(addr + RAM_OFFSET, data);
    cout << name() << " read(" << addr << ", " << data << ")" 
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);
    // Write to second adder input
    initiator_port->write(ADDER_INPUT2, data);
    cout << name() << " write(" << addr << ", " << data << ")" 
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);

    // Read from adder output
    initiator_port->read(ADDER_OUTPUT, data);
    cout << name() << " read(" << addr << ", " << data << ")" 
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);
    // Write to sum RAM
    initiator_port->write(SUM_RAM_START + addr, data);
    cout << name() << " write(" << addr << ", " << data << ")" 
         << " at " << sc_time_stamp() << endl;
    wait(1, SC_NS);
  }

  wait();
}
