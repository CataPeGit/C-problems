
vector<string> Puzzle::bfs_path(string start_node, string end_node)
{
	// first we apply breadth-first search
	//then we reconstruct the path from start to end
	int number_of_nodes_in_graph = graph.number_of_nodes_in_graph();

	// Breadth-first search

	queue<string> node_queue;
	node_queue.push(start_node);

	//pairing each string(node) to a bool representing if the node was visited
	map<string, bool> visited;

	map<string, vector<string>>::iterator it = graph.get_vertices().begin();

	for (it ; it != graph.get_vertices().end(); it++)
	{
		visited.insert(std::pair<string, bool>(it->first, false));
		std::cout << it->first;
	}

	/*
	for (auto const& x : graph.get_vertices())
	{
		visited.insert({ x.first, false });
	}
	*/
	
	std::cout << "\n" << visited.find("*aab")->second;
	visited.find(start_node)->second = true;

	map<string, string> previous;
	previous.insert({start_node, "null"});

	while (!node_queue.empty()) {
		string current_node = node_queue.front();
		node_queue.pop();
		vector<string> current_neighbours = graph.get_vertices().at(current_node);

		for (string next_node : current_neighbours) {
			if (!visited.find(start_node)->second) {
				node_queue.push(next_node);
				visited.find(start_node)->second = true;
				previous.at(next_node) = current_node;
			}
		} 
	}

	// Reconstruct path going backwards from the end
	vector<string> result_path;
	for (string pos = end_node; pos != "null"; pos = previous.at(pos)) {
		result_path.push_back(pos);
	}
	result_path.reserve(number_of_nodes_in_graph);

	if (result_path[0] == start_node) {
		return result_path;
	}
	return vector<string>();
}

vector<string> Puzzle::bfs_path(string start_node, string end_node)
{
	// first we apply breadth-first search
	//then we reconstruct the path from start to end

	// Create queue
	list<string> queue;

	// Create maps which keep track of visited nodes and their distance from the root
	map<string, bool> visitedm;
	map<string, int> distm;
	map<string, string> predm;

	map < string, vector<string>>::iterator it = graph.get_vertices().begin();
	for (it; it != graph.get_vertices().end(); ++it) {
		visitedm.insert(std::pair<string, bool>(it->first, false));
		predm.insert(std::pair<string, string>(it->first, ""));
		distm.insert(std::pair<string, int>(it->first, INT_MAX));
	}
	std::cout << visitedm.find(start_node)->second;
	visitedm.find(start_node)->second = true;
	distm.find(start_node)->second = 0;
	queue.push_back(start_node);
	bool done = false;
	while (!queue.empty()) {
		string current = queue.front();
		queue.pop_front();

		// Go through all neighbours of current node and search

		map<string, vector<string>>::iterator currentNeigh = graph.get_vertices().find(current);

		for (int i = 0; i < currentNeigh->second.size(); i++) {
			string currentNode = currentNeigh->second[i];
			std::cout << visitedm.find(currentNode)->second;
			if (visitedm.find(currentNode)->second == false) {
				visitedm.find(currentNode)->second = true;
				distm.find(currentNode)->second = distm.find(current)->second + 1;
				predm.find(currentNode)->second = current;
				queue.push_back(currentNeigh->second[i]);

				if (currentNeigh->second[i] == end_node) {
					done = true;
					break;
				}
			}

		}

		if (done)
			break;
	}

	// We have the shortest path stored in dist, we now place it in a vector and return it
	vector<string> path;
	string crawl = end_node;
	path.push_back(end_node);
	while (predm[crawl] != "") {
		path.push_back(predm[crawl]);
		crawl = predm[crawl];
	}

	return path;

}
