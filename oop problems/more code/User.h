#pragma once
#include <string>

using std::string;

class User {

	//should probably turn this into a template to have a base user interface, then we add features
	//based on the user type, i.e. student, veteran, lucrator la buget, basic package (care ar putea fi direct ce e in template i guess), pensionar, etc.

	unsigned int get_id() const;
	string get_name() const;
	unsigned int get_account_balance() const;

	void add_to_balance(unsigned int value_to_add);
	void change_balance(unsigned int new_balance);
	void substract_from_balance(unsigned int substracted_value);


private:	
	unsigned int id;
	string name;
	unsigned int account_balance;
	// tickets/vouchers maybe
	// sa fac un array "spent_money_on" in care sa adaug pe ce am cheltuit banii
	// maybe map money_spent to item_bought
	// add a wishlist
	// maybe take money from account_balance to a fond for a certain item/ dark days/ college/ a course
	// have an ammount reserved each month for necessities, second tier necessities and extra things
	// maybe show what you can affort or not affor from each tier
	// like u add a sum for the month and you see what you will be able to afford with that sum
	// add saved_money

	// maybe expand this to a asset manager
	// maybe expand this to give suggestions on what assets to buy with the money saved 
	

};