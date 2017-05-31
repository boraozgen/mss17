#include "multiplier.h"
void Multiplier::multiply()
{
  int a;
  while(1) {
    a = in.read();
    out.write(a*K);
    cout << "Multiplier: input " << a << ", factor " << K;
    cout << ", output " << a*K << endl;
  }
}
