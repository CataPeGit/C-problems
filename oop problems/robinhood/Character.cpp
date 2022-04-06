#include "Character.h"

Character::Character() {
	name = "";
	strength = 0;
}
Character::Character(string _name, double _strength) {
	name = _name;
	strength = _strength;
}
