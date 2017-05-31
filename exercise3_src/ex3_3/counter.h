#ifndef _COUNTER_H_
#define _COUNTER_H_
#include "systemc.h"
#include "register.h"

class Counter : public Register 
{
private:
  // data members (attributes)
  sc_uint<8> modulus;
  bool overflow_flag;
  
public:
  // member functions (methods)
  Counter(sc_uint<8> mod)
  {
	  modulus = mod;
	  overflow_flag = false; 
	  state=0;
  }

  void count()
  {
	  if(state==(modulus-1))    { 
		  overflow_flag = true;
		  state = 0;
	  }
	  else
		  state = state+1;
  }
     
  bool overflow()
  {
	  if(overflow_flag==true) { 
		  overflow_flag = false;
		  return true;
	  }
	  else
		  return false;	 
  }
  sc_uint<8>  read_mod()
  {
    return modulus;
  }
};

#endif
