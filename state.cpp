#include "state.h"

bool state::is_finite() {
	return finite;
}

bool state::is_primary() {
	return primary;
}

int state::get_id() {
	return id;
}

state::state(int n, bool h=0, bool p=0):id(n), finite(h), primary(p) {}
