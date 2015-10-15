#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <iostream>
#include "CartPoint.h"
using namespace std;

//declaring class GameObject
class GameObject
{
private:
	int id_num;
protected:
	CartPoint location; //location of object
	char display_code;  //how object is represented in the View
	char state;   		//state of the object
public:

	//initializes id_num, display_code, and location(to 0,0)
	GameObject(char in_code, int in_id);

	//initializes id_num, display_code, and location.
	GameObject(char in_code, int in_id, CartPoint in_loc);

	virtual ~GameObject(); 

	//returns location for the GameObject
	CartPoint get_location();

	char get_display_code();
	char get_state();

	//returns id_num for the GameObject
	int get_id();

	//outputs information on display_code, id_num, and location.
	virtual void show_status();

	virtual bool update() = 0;

	void drawself(char*); 
};

#endif