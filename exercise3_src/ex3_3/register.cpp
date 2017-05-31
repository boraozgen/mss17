#include "register.h"

void Register::reset()
{
  state = 0;
}

void Register::load(sc_uint<8> d)
{
  state = d;
}

sc_uint<8>  Register::read()
{
  return state;
}
