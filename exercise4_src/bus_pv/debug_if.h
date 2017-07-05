#ifndef _DEBUG_IF_H_
#define _DEBUG_IF_H_

#include "systemc.h"

class debug_if : virtual public sc_interface
{
	virtual void dump(ostream &os) = 0;
};

#endif
