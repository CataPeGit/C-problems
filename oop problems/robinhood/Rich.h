#pragma once
#include "Character.h"

class Rich: public Character {
public:
	Rich();
	Rich(unsigned int treasure);

	unsigned int get_treasure() const;

protected:
	unsigned int m_treasure;
};