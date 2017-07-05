#include "new_master.h"

void New_master::action()
{
  unsigned status = 0;

  wait(1000, SC_NS);

  initiator_port->write(1024, 0, id);
  initiator_port->write(1025, 16, id);
  initiator_port->write(1026, 64, id);
  initiator_port->write(1027, 16, id);
  initiator_port->write(1028, 1, id);

  wait(10, SC_NS);
  initiator_port->read(1028, status, id);

  while (status) {
    wait(10, SC_NS);
    initiator_port->read(1028, status, id);
  }

  cout << "Status 0 " << " at " << sc_time_stamp() << ". Stopping simulation." << endl;

  sc_stop();
}
