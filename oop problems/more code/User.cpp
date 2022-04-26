#include "User.h"

unsigned int User::get_id() const {
	return id;
}
string User::get_name() const {
	return name;
}

unsigned int User::get_account_balance() const {
	return account_balance;
}

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
