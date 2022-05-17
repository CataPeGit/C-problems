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
	// reading the data file and creating patterns for all words  which are added to the map
	ifstream words_file;
	words_file.open(filePath);

	map<string, vector<string>> result;
	string word;
	while (getline(words_file, word)) {
		words_file >> word;

		if (word.size() == length) {
			create_possible_patterns(result, word);
		}
	}

	words_file.close();

	return result;
}

void Puzzle::fill_graph_with_all_words(string filePath, int length)
{
	// filling the graph with all words in a file of a given length
	graph.set_vertices(get_all_words(filePath, length));
}

void Puzzle::create_possible_patterns(map<string, vector<string>>& word_map, string word)
{
	// looping trough the word and changing each letter with *
	// this way we create a pattern and we add it to the map
	vector<string> new_patterns;
	for (int i = 0; i < word.size(); i++) {

		string pattern = word;
		pattern[i] = '*';
		new_patterns.push_back(pattern);
	}

	pair<map<string, vector<string>>::iterator, bool> check;
	check = word_map.insert(pair<string, vector<string>>(word, new_patterns));

	if (check.second == false) {
		check.first->second.push_back(word);
	}

	//std::cout << check.first->first << "\n\n";

	//std::cout << check.first->second[0] << check.first->second[1] << "\n\n\n\n\n\n\n\n";

}

Graph<string> Puzzle::create_graph_from_map(map<string, vector<string>> word_map)
{
	// adding all words to the graph and then connecting them
	Graph<string> result;

	for (auto const& x : word_map)
	{
		for (auto i : x.second) {
			result.add_node(i);
		}
	}

	for (auto const& x : word_map)
	{
		for (auto i : x.second) {
			for (auto j : x.second) {
				if (i != j)
					result.connect_two_nodes(i, j);
			}
		}
	}

	return result;
}



