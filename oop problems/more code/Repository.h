#pragma once

#include "User.h"
#include <vector>

class Repository {

	friend class User;

public:

	Repository();
	Repository(const Repository& _other);
	~Repository();

	std::vector<User> get_rep() const;
	unsigned int get_latest_user_id() const;

	void add_user_to_repository(User user);
	void remove_user_from_repository(User user);
	void clear_repository();

private:
	std::vector<User> user_repository;

};