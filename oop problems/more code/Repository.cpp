#include "Repository.h"

Repository::Repository(){
}

Repository::Repository(const Repository& _other){
	user_repository = _other.user_repository;
}

Repository::~Repository(){
}

std::vector<User> Repository::get_rep() const
{
	return user_repository;
}

unsigned int Repository::get_latest_user_id() const
{
	return user_repository.size();
}

void Repository::add_user_to_repository(User user){
	user_repository.push_back(user);
}

void Repository::remove_user_from_repository(User user){
	// search trough the repository for the user by id user and remove him 
	remove_if(
		user_repository.begin(),
		user_repository.end(),
		[user](User user_in_rep) {
			if (user.get_id() == user_in_rep.get_id()) {
				return true;
			}
			return false;
		}
	);
}

void Repository::clear_repository(){
	user_repository.clear();
}
