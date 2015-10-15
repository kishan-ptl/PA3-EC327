#include <iostream>
#include "GameObject.h"
#ifndef CORALREEF_H
#define CORALREEF_H
using namespace std;

class CoralReef: public GameObject
{
private:
	double amount; //amount of food in the reef
	
public:
	//initializes display_code to 'R' and state to 'f'
	CoralReef(); 

	//initializes id_num, location, and display_code
	CoralReef(int in_id, CartPoint in_loc); 

	~CoralReef();
	
	//returns true only if CoralReef contains 0 food
	bool is_empty();

	//provides 20 food if the coral reef has enough. if not it gives what it has
	double provide_food(double amount_to_provide = 20);

	//if reef is empty, state = 'e', display_code = 'r', returns true
	//prints "CoralReef <id_num> has been depleted"

	//only return true when CoralReef gets depleted, not afterwards.
	bool update();

	//prints status of the object (display_code, id_num, location, amt of food)
	void show_status();
};

#endif

