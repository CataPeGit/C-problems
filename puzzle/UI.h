#pragma once
#include "Puzzle.h"
#include <iostream>
#include "Exceptions.h"

using std::cout;
using std::cin;

class UI {

public:

	// Constructors
	UI();

	UI(const UI& other_ui);

	// Destructor
	~UI();

	// Display menu
	void display_menu();

	// Taking user input command
	string take_user_input();

	// Automatic mode
	void automatic_mode();

	// Starts the game
	void start();

private:
	
	friend class Puzzle;
};