#include "ram.h"

void Ram::write( unsigned addr, unsigned  data )
{
  if( (addr < start) || (addr >= start + sz) )
    cout << name() << " write(" << addr << ", __) : ERROR address out of range"
    << endl;
  else
    mem[addr-start] = data;
}

void Ram::read(  unsigned addr, unsigned &data )
{
  if( (addr < start) || (addr >= start + sz) )
    cout << name() << " read(" << addr << ", __) : ERROR address out of range"
    << endl;
  else
    data = mem[addr-start];
}
  

