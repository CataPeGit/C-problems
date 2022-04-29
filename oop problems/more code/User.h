#pragma once
#include <string>
#include <map>
#include <ostream>
#include <iostream>

using std::string;
using std::map;
using std::ostream;

//template<typename ElementType>

class User {

public:

	// Rule of three
	User() {
		id = NULL;
		name = "";
		account_balance = 0;
		purchased_price[""] = NULL;
	}
	User(const User& other_user) {
		id = other_user.get_id();
		name = other_user.get_name();
		account_balance = other_user.get_account_balance();
		purchased_price = other_user.get_purchased_price();
	}
	~User() {

	}

	User(unsigned int _id, string _name, unsigned int _account_balance, std::map<std::string, unsigned int> _purchased_price) {
		id = _id;
		name = _name;
		account_balance = _account_balance;
		purchased_price = _purchased_price;
	}


	// getters
	unsigned int get_id() const {
		return id;
	}
	string get_name() const {
		return name;
	}

	unsigned int get_account_balance() const {
		return account_balance;
	}

	std::map<std::string, unsigned int> get_purchased_price() const {
		return purchased_price;
	}

	unsigned int get_specific_purchase_price(string item_name) {
		return purchased_price[item_name];
	}

	unsigned int get_total_balance_spent() {
		// looping trough the map and calculating the total balance spent
		unsigned int spent = 0;
		for (auto& key_value : purchased_price) {
			spent += key_value.second;
		}
		return spent;
	}

	// setters and modifiers
	void set_specific_purchase_price(string item_name, unsigned int new_price) {
		purchased_price[item_name] = new_price;
	}

	void set_balance(unsigned int new_balance)
	{
		account_balance = new_balance;
	}

	void add_to_balance(unsigned int value_to_add)
	{
		account_balance += value_to_add;
	}

	void substract_from_balance(unsigned int substracted_value)
	{
		account_balance -= substracted_value;
	}

	void add_purchase(string item_name, unsigned int item_price) {
		// add a new purchase to the purchases map
		if (!check_if_purchase_exists(item_name)) {
			// item not found 
			purchased_price[item_name] = item_price;
		}
		else {
			// item found
			purchased_price[item_name] +=  item_price;
		}
	}

	void remove_purchase(string item_name) {
		// remove purchase from map
		if (check_if_purchase_exists(item_name)) {
			purchased_price.erase(item_name);
		}
		else {
			//std::cout << "Item not purchased";
			throw 404;
		}

	}

	bool check_if_purchase_exists(const string& item_name) {
		if (purchased_price.find(item_name) == purchased_price.end()) {
			// item not found
			return false;
		}
		// item found
		return true;
	}

	// view/display functions
	void view_purchases() const {
		// looping trough and displaying the items in the map
		for (auto& key_value : purchased_price) {
			std::cout << key_value.first << ": " << key_value.second << std::endl;
		}
	}

	// operator overloads
	friend ostream& operator<<(ostream& out, const User& user) {
		// Output general information about the user
		out << "Name: " << user.get_name() << std::endl;
		out << "Id: " << user.get_id() << std::endl;
		out << "Account Balance: " << user.get_account_balance() << std::endl;
		return out;
	}

private:	
	// user id
	unsigned int id;
	// name of the user
	string name;
	// the current balance of the user
	unsigned int account_balance;
	// mapping items purchased by the user to their price
	// in order to keep track of what items the user bought and the money they spent
	std::map<std::string, unsigned int> purchased_price; 
};
