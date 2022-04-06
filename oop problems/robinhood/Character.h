#pragma once
#include <string>
using std::string;

class Character {
public:
	Character();
	Character(string _name, double _strength);

protected:
	string name;
	double strength;
};