#include <iostream>
#include "CoralReef.h"
using namespace std; 

CoralReef::CoralReef() : GameObject('R', 0)
{
	state = 'f';
	amount = 100;
	cout << "CoralReef default constructed" << endl;
}

CoralReef::CoralReef(int in_id, CartPoint in_loc) : GameObject('R', in_id, location)
{	
	location = in_loc;
	state = 'f';
	amount = 100;
	cout << "CoralReef constructed" << endl;
}

CoralReef::~CoralReef()
{
	cout << "CoralReef destructed" << endl;
}

bool CoralReef::is_empty()
{
	if (amount == 0) {
		return true;
	}

	else {
		return false; 
	}
}

double CoralReef::provide_food(double amount_to_provide)
{
	if (amount >= amount_to_provide)
	{
		amount = amount - amount_to_provide;
		return amount_to_provide;
	}

	else
	{
		amount_to_provide = amount;
		return amount_to_provide;
		amount = 0;
	}
}

bool CoralReef::update()
{
	static bool alreadyempty = false;
	if (amount == 0) 
	{
		if (alreadyempty) 
		{
			return false;
		}
		state = 'e';
		display_code = 'r';
		cout << "CoralReef " << get_id() << " has been depleted" << endl;
		alreadyempty = true;
		return true;
	}
	else 
	{
		return false;
	}
}

void CoralReef::show_status()
{
	cout << "CoralReef Status: " << display_code << " with ID " << get_id()
	<< " at location " << location << " containing food " << amount << endl;
}