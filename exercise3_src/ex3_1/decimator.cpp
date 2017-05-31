#include "decimator.h"
void Decimator::decimate()
{
    int a;
    while(1) {
      for(int i=0; i<N-1; i++) {
	a = in.read();
	cout << "Decimator: input " << a << " discarded" << endl;
      }
      a = in.read();
      out.write(a);
      cout << "Decimator: input " << a << " used" << endl;
    }
}
