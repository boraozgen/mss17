#include "adapter.h"

void Adapter::write(unsigned addr, unsigned  data) {
  switch(addr) {
  case 1024 :
    x.write(data);
    break;
  case 1025 :
    y.write(data);
    break;
  default :
    cout << "Adapter: write to invalid address" << endl;
  }
}

void Adapter::read( unsigned addr, unsigned &data) {
  switch(addr) {
  case 1024 :
    data = x.read();
    break;
  case 1025 :
    data = y.read();
    break;
  case 1026 :
    data = s.read();
    break;
  default :
    cout << "Adapter: read from invalid address" << endl;
  }
}
