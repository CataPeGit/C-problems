#pragma once
#include "Character.h"
#include "Rich.h"
class Outlaw: public Character {

	Outlaw();
	Outlaw(unsigned int _sz);
	~Outlaw();	
	void steal(unsigned int treasure);

protected:
	unsigned int sz;
	unsigned int* chests;
};
