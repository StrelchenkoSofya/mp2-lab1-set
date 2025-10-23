#pragma once
#include"tset.h"

class svet {
protected:
	TSet s = TSet(1);
	size_t n;
	int step;
public:
	svet() : n(0), step(0) {};
	svet(int count) {
		n = count;
		TSet s2(n);
		s = s2;
		step = 0;
		set_active(0);
	}
	void change();
	void set_active(int s);
	int return_active();
	size_t return_n() { return n; };
};

class pesh_svet : public svet {
public:
	pesh_svet() : svet(2) {};
};

class avt_svet : public svet {
public:
	avt_svet() : svet(3) {};
};

class inter {
public:
	void show_color(svet sv);
};

class road {
	inter inter;
	pesh_svet ps;
	avt_svet as;
public:
	road() : ps(), as() {
		ps.set_active(0);
		as.set_active(2);
	}
	void work();
};