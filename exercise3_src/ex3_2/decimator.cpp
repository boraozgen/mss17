#include "decimator.h"
void Decimator::decimate()
{
    int a;
    while(1) {
      for(int i=0; i<N-1; i++) {
		  a = input.read();
#ifdef DEBUG_ENABLED
		  cout << name() << ": input " << a << " discarded" << endl;
#endif
      }
      a = input.read();
      out.write(a);
#ifdef DEBUG_ENABLED
      cout << name() << ": input " << a << " used" << endl;
#endif
    }
}
