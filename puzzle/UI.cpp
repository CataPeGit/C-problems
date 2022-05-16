#include "UI.h"

// Constructors
UI::UI()
{
}

UI::UI(const UI& other_ui)
{
}

// Destructor
UI::~UI()
{
}

void UI::display_menu()
{
	// Displaying the menu to the user
	cout << "Welcome! \n\n";
	cout << "Menu: \n";
	cout << "A|a    Automatic mode \n";
	cout << "P|p    Playing mode \n";
	cout << "S|s    Statistics (analytics module) \n";
	cout << "D|d    Display menu \n";
	cout << "Q|q    Quit \n";
	cout << "\n Your input: ";
}

string UI::take_user_input()
{
	// reading user input and returning it as a string 
	string command;
	getline(cin, command);
	cout << "\n";
	return command;
}

void UI::automatic_mode()
{
	// You select the starting word and the target word
	// and the application displays the transformations you need to perform
	
	// Taking the length of the words as input and validating
	int input_length;
	cout << "Pick words length: ";
	cin >> input_length;
	cout << "\n";

	while (!cin.good())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input, please pick a number bigger than 0. \n";
		cout << "Pick words length: ";
		cin >> input_length;
		cout << "\n\n";
	}
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// creating the graph
	Puzzle puzzle;
	puzzle.get_graph();
	puzzle.fill_graph_with_all_words("words_alpha.txt", input_length);
	
	// Taking the starting word as input and validating
	string start_word;
	bool is_word_valid = false;
	cout << "Please input the starting word: ";
	/*
	while (!is_word_valid) {
		getline(cin, start_word);
		try {
			
			if (puzzle.get_graph().get_vertices().find(start_word) == puzzle.get_graph().get_vertices().begin()) {
				throw wordExceptions("Invalid Word!");
			}
			else
			{
				is_word_valid = true;
			}
		}
		catch (wordExceptions& e) {
			cout << e.what() ;
		}
	}	
	*/
	getline(cin, start_word);
	cout << "\n";

	// Taking the target word as input and validating
	string target_word;
	is_word_valid = false;
	cout << "Please input the target word: ";
	/*
	while (!is_word_valid) {
		try {
			getline(cin, target_word);
			if (puzzle.get_graph().get_vertices().find(target_word) == puzzle.get_graph().get_vertices().end()) {
				throw wordExceptions("Invalid Word!");
			}
			else
			{
				is_word_valid = true;
			}
		}
		catch (wordExceptions& e) {
			cout << e.what();
		}
	}	
	*/
	getline(cin, target_word);
	cout << "\n";

	// getting the best path from the starting to the target word and displaying it
	
	cout << "start: " << start_word << " end:" << target_word;

	vector<string> best_path = puzzle.bfs_path(start_word, target_word);

	cout << "The transformations you neet to perform: \n";

	for (string current_word : best_path) {
		cout << current_word << "\n";
	}
	cout << "\n";
	
}

void UI::start()
{
	// starts the game and takes care of the logic behind it


	while (true) {

		display_menu();
		string user_input = take_user_input();
		
		if (user_input == "A" || user_input == "a") {
			automatic_mode();
		}

	}

}
