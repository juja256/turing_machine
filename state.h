#ifndef STATE_H
#define STATE_H

class state {
	int id;
	bool finite;
	bool primary;
public:
	bool is_finite();
	bool is_primary();
	int get_id();
	state(int n, bool h, bool p);
};

#endif
