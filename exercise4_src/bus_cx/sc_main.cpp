#include "master.h"
#include "ram.h"
#include "bus_cx.h"
#include "adapter.h"
#include "adder.h"
#include "master_add.h"

int sc_main(int argc, char *argv[])
{
  Master master1("master1", 0, 17, 0);
  Ram    ram1("ram1", 0, 16);
  Master master2("master2", 20, 31, 1);
  Ram    ram2("ram2", 16,16);
  Bus_cx bus("bus", 10, SC_NS);
  Adapter adp("adp");
  Adder adder("adder");
  MasterAdd master3("master3", 0, 15, 2);
  Ram ram3("ram3", 64, 16);
  sc_signal<int> ch_x, ch_y, ch_s;

  master1.initiator_port(bus.bus_export);
  master2.initiator_port(bus.bus_export);
  master3.initiator_port(bus.bus_export);
  bus.bus_port(ram1.target_export);
  bus.bus_port(ram2.target_export);
  bus.bus_port(ram3.target_export);
  bus.bus_port(adp.target_export);
  adp.x(ch_x);
  adp.y(ch_y);
  adp.s(ch_s);
  adder.x(ch_x);
  adder.y(ch_y);
  adder.s(ch_s);

  sc_start();

  cout << "Ram1" << endl;
  ram1.dump(cout);
  cout << "Ram2" << endl;
  ram2.dump(cout);
  cout << "Ram3" << endl;
  ram3.dump(cout);
  return 0;
}
