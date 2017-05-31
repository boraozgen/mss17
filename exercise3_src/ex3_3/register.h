#ifndef _REGISTER_H_
#define _REGISTER_H_
#include "systemc.h"

class Register
{
protected:
  // data members (attributes)
  sc_uint<8> state;
  
public:
  // member functions (methods)
  void reset();
  void load(sc_uint<8>);
  sc_uint<8> read();
  };

#endif
