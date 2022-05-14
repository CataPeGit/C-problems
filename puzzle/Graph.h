#pragma once
#include <vector>
#include <map>


using std::vector;
using std::map;
using std::pair;

template <typename ElementType>
struct Node {
	// the value store inside the node (a word)
	ElementType node_value;

	// Adjacency list that contains all node neighbours
	vector<Node<ElementType>*> neighbours;
};

template <typename ElementType>
class Graph {

public:

	// default constructor
	Graph(){}

	// destructor
	~Graph() {
		graph_vertices.clear();
	}

	// returning all vertices in the graph
	map<ElementType, vector<ElementType>> get_vertices() {
		return graph_vertices;
	}
	
	// change the graph by replacing all vertices
	void set_vertices(map<ElementType, vector<ElementType>> new_vertices) {
		graph_vertices = new_vertices;
	}

	// if the node does not exist we add it to the graph
	void add_node(ElementType value) {
		if (graph_vertices.find(value) == graph_vertices.end()) {
			graph_vertices.insert(pair<ElementType, vector<ElementType>>(value, vector<ElementType>()));
		}
	}

	// connecting two nodes if they exist in the graph
	void connect_two_nodes(ElementType node_one, ElementType node_two) {

		if (graph_vertices.find(node_one) != graph_vertices.end() && graph_vertices.find(node_two) != graph_vertices.end()) {
			graph_vertices[node_one].push_back(node_two);
			graph_vertices[node_two].push_back(node_one);
		}

	}

	// check if two nodes are neighbours
	bool check_neighbours(ElementType node_one, ElementType node_two) {

		if (graph_vertices[node_two].find(node_one) != graph_vertices.end() && graph_vertices[node_one].find(node_two) != graph_vertices.end()) {
			return true;
		}

		return false;
	}

private:

	// mapping all vertices to their neighbours
	map<ElementType, vector<ElementType>> graph_vertices;

};

