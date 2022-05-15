#pragma once
#include "Graph.h"
#include <string>
#include <ostream>
#include <iostream>
#include <fstream>
#include <queue>
#include <utility>

using std::pair;
using std::queue;
using std::string;
using std::ifstream;
using std::getline;

#include<list>
using std::list;

class Puzzle : public Graph<string> {

public:

	Puzzle();
	Puzzle(const Puzzle& other_puzzle);
	~Puzzle();

	// getting the current graph
	Graph<string> get_graph() const;

	// getting all words of a given length from the file containg all words into a map
	map<string, vector<string>> get_all_words(string filePath, int length);

	// adding all words from "get_all_words" to the current "graph" object
	void fill_graph_with_all_words(string filePath, int length);

	// a pattern is defined by a word in which one and only one of its letters have been replaced by a *
	// and therefore it can be replaced by any letter
	// this function creates all possible pattern for a given word
	// and adds them to the map given as a parameter
	void create_possible_patterns(map<string, vector<string>>& word_map, string word);

	// creating a graph containing all words from a map
	Graph<string> create_graph_from_map(map<string, vector<string>> word_map);

	vector<string> bfs_path(string start_node, string end_node);



private:
	
	friend class Graph<string>;
	
	Graph<string> graph;

};
