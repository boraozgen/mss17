#include "multiplier.h"
void Multiplier::multiply()
{
  int a;
  while(1) {
    a = in.read();
    out.write(a*K);
#ifdef DEBUG_ENABLED
    cout << name() << ": input " << a << ", factor " << K;
    cout << ", output " << a*K << endl;
#endif
  }
}
