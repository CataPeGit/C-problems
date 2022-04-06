#include "Outlaw.h"

Outlaw::Outlaw() {
	sz = 0;
	chests = nullptr;
}

Outlaw::Outlaw(unsigned int _sz) {
	sz = _sz;
	chests = new unsigned int[sz];
}

Outlaw::~Outlaw() {
	delete chests;
}

void Outlaw::steal(unsigned int treasure) {
	
}