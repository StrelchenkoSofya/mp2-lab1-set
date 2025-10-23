#include "svetofor.h"
#include<iostream>

void svet::set_active(int a) {
	for (int i = 0; i < n; i++) {
		s.DelElem(i);
	}
	s.InsElem(a);
}
int svet::return_active() {
	for (int i = 0; i < n; i++) {
		if (s.IsMember(i)) {
			return i;
		}
	}
}
void svet::change() {
	if (s.IsMember(0)) {
		step = 1;
	}
	else if (s.IsMember(n -	1)) {
		step = -1;
	}
	this->set_active(this->return_active() + step);
}

void inter::show_color(svet sv) {
	size_t n = sv.return_n();
	int act_s = sv.return_active();
	if (n == 2) {
		std::cout << "P: ";
	}
	else if (n == 3) {
		std::cout << "A: ";
	}
	else {
		std::cout << "?: ";
	}
	if (act_s == n - 1) {
		std::cout << "green" << std::endl;
	}
	else if (act_s == 0) {
		std::cout << "red" << std::endl;
	}
	else {
		std::cout << "yellow" << std::endl;
	}
}

void road::work() {
	as.change();
	if (as.return_active() != 1) {
		ps.change();
	}
	inter.show_color(as);
	inter.show_color(ps);
}

