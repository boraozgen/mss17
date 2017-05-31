#include "dst.h"
void dst::behaviour()
{
	int received_value;
	if(input.nb_read(received_value))
		cout << (char) received_value;

	next_trigger(input.data_written_event());
}
