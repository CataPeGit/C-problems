#include "Puzzle.h"

Puzzle::Puzzle()
{
	graph = Graph<string>();
}

Puzzle::Puzzle(const Puzzle& other_puzzle)
{
	graph = other_puzzle.graph;
}

Puzzle::~Puzzle()
{
	graph.~Graph();
}

Graph<string> Puzzle::get_graph() const
{
	return graph;
}

map<string, vector<string>> Puzzle::get_all_words(string filePath, int length)
{
	// reading the data file and adding all words of a given length to a map
	ifstream words_file;
	words_file.open("words_alpha.txt");

	map<string, vector<string>> result;
	string word;
	while (getline(words_file, word)) {
		words_file >> word;
		if (word.size() == length) {
			//add word to map 
		}
	}
	words_file.close();

}

