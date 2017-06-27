#include "adapter.h"

void Adapter::write( unsigned addr, unsigned  data )
{
  if( (addr < start) || (addr >= start + sz) )
    cout << name() << " write(" << addr << ", __) : ERROR address out of range" << endl;
  else if( addr == ADDER_INPUT1 )
  {
	 x.write(data);
	 mem[0] = data;
	 cout << "write x: " << mem[0] << endl;
  }
  else if( addr == ADDER_INPUT2 )
  {
	 y.write(data);
	 mem[1] = data;
	 cout << "write y: " << mem[1] << endl;
  }
  else if( addr == ADDER_OUTPUT )
    cout << name() << " write(" << addr << ", __) : ERROR writing to output port is not allowed" << endl;
  else
    cout << name() << " write(" << addr << ", __) : ERROR address out of range" << endl;
}

void Adapter::read(  unsigned addr, unsigned &data )
{
  if( (addr < start) || (addr >= start + sz) )
    cout << name() << " read(" << addr << ", __) : ERROR address out of range" << endl;
  else if( addr == ADDER_INPUT1 )
  {
	 data = mem[0];
	 cout << "read x: " << mem[0] << endl;
  }
  else if( addr == ADDER_INPUT2 )
  {
	 data = mem[1];
	 cout << "read y: " << mem[1] << endl;
  }
  else if( addr == ADDER_OUTPUT )
  {
	 data = s.read();
	 mem[2] = data;
	 cout << "read s: " << mem[2] << endl;
  }
  else
    cout << name() << " read(" << addr << ", __) : ERROR address out of range" << endl;
}
