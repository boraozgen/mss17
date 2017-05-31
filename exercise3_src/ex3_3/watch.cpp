#include "watch.h"

void Watch::inc_sec() {
	sec.count();
	if (sec.overflow()) {
		next_minute.notify();
	}
}

void Watch::inc_min() {
	min.count();
	if (min.overflow()) {
		next_hour.notify();
	}
}

void Watch::inc_hour() {
	hour.count();
	hour.overflow(); // to reset the overflow flag
}

void Watch::write_time() {
	cout << hour.read() << ":" << min.read() << ":" << sec.read() << endl;
}
