#pragma once

#include "User.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using std::string;
using std::map;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::vector;

class Repository {

	friend class User;

public:
	friend vector<string> tokenize(string str, char delimiter);
	Repository();
	Repository(const Repository& _other);
	~Repository();

	std::vector<User> get_rep() const;
	unsigned int get_size() const;

	void add_user_to_repository(User user);
	void remove_user_from_repository(User user);
	void clear_repository();

	void read_from_file();
	void write_to_file();

private:
	std::vector<User> user_repository;

};
