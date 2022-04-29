#pragma once
#include <string>
#include <map>
using std::string;
using std::map;


class User {

public:
	// rule of three
	User();
	User(const User& other_user);
	~User();

	User(unsigned int _id,string _name,unsigned int _account_balance,std::map<std::string, unsigned int> _spent_money_on);
	
	// getters
	unsigned int get_id() const;
	string get_name() const;
	unsigned int get_account_balance() const;
	std::map<std::string, unsigned int> get_spent_money_on() const;

	// setters
	void add_to_balance(unsigned int value_to_add);
	void change_balance(unsigned int new_balance);
	void substract_from_balance(unsigned int substracted_value);


private:	
	unsigned int id;
	string name;
	unsigned int account_balance;
	std::map<std::string, unsigned int> spent_money_on; 

};
