#include "User.h"

User::User() {
	id = NULL;
	name = "";
	account_balance = 0;
	spent_money_on[""] = 0;
}
User::User(const User& other_user) {
	id = other_user.get_id();
	name = other_user.get_name();
	account_balance = other_user.get_account_balance();
	spent_money_on = other_user.get_spent_money_on();
}
User::~User() {

}

User::User(unsigned int _id, string _name, unsigned int _account_balance, std::map<std::string, unsigned int> _spent_money_on) {
	id = _id;
	name = _name;
	account_balance = _account_balance;
	spent_money_on = _spent_money_on;
}

// getters
unsigned int User::get_id() const {
	return id;
}
string User::get_name() const {
	return name;
}

unsigned int User::get_account_balance() const {
	return account_balance;
}

std::map<std::string, unsigned int> User::get_spent_money_on() const {
	return spent_money_on;
}

//setters
void User::add_to_balance(unsigned int value_to_add)
{
	account_balance += value_to_add;
}

void User::change_balance(unsigned int new_balance)
{
	account_balance += new_balance;
}

void User::substract_from_balance(unsigned int substracted_value)
{
	account_balance += substracted_value;
}
