#include "adder.h"
void Adder::add()
{
  int a, b;
  while(1) {
    a = in1.read(); b = in2.read();
    out.write(a+b);
    cout << "Adder: in1 " << a << ", in2 " << b;
    cout << ", output " << a+b << endl;
  }
}
