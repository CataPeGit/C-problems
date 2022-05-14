#pragma once
#include "Graph.h"
#include <string>
#include <ostream>
#include <iomanip>
#include <fstream>

using std::string;
using std::ifstream;
using std::getline;

class Puzzle {

public:

	Puzzle();
	Puzzle(const Puzzle& other_puzzle);
	~Puzzle();

	// getting the current graph
	Graph<string> get_graph() const;

	// getting all words of a given length from the file containg all words
	map<string, vector<string>> get_all_words(string filePath, int length);

private:
	
	friend class Graph<string>;
	
	Graph<string> graph;

};









