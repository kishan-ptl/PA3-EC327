#ifndef FISH_H
#define FISH_H
#include <iostream>
#include "GameObject.h"
#include "CartVector.h"
#include "CoralReef.h"
#include "Cave.h"

class Cave;
class CoralReef;
class Fish : public GameObject
{
	friend class Cave;
	friend class CoralReef;
private:
	double energy; //health of the fish. initial value = 15
	double size; //size of the fish. initial value = 10
	double prefeast_size; //size of fish before eating. initial value = size

	CartPoint destination; //current destination in coordinates. initial value = (0,0)
	CartVector delta; //x and y amounts that the object will move per unit time

	CoralReef* reef; //pointed to the CoralReef to be eaten from. initial value = NULL

	Cave* home; //pointer to the Cave where fish will hide
	//initialized to the birthplace of the fish
	//can be changed by start_hiding function
	//default constructor sets to NULL

	bool update_location(); //updates location while fish is moving
	//sees whether fish is at destination or needs to keep swimming

//sets up object to move to dest by setting destination pointer and calculating delta
	void setup_destination(CartPoint dest);

public:	
	//DEFAULT CONSTRUCTOR
	Fish();	//display_code 'F', state 'h' (because initially hidden)
	//prints "fish default constructed"

	Fish(int in_id, Cave* home); //sets ID and initial location using supplied values
	//hides the fish inside home Cave (decreasing Cave space by size)
	//prints "Fish constructed"

	~Fish();

	bool update(); //switch statement
	//returns true if state has changed
	//updates status of the object at each time unit

	double get_size(); //returns size of the fish

	void start_swimming(CartPoint dest); //tells fish to swim towards dest
	//calls setup_destination function
	//sets state to 's' for swimming
	//prints 

	void start_eating(CoralReef* destReef); //tells fish to eat at destReef
	//will return to Cave home after doubling in size
	//calls setup_destination function
	//sets state to 'o' for outbound
	//prints

	bool is_hidden(); //returns true if fish is hidden. otherwise false

	void start_hiding(Cave* destCave); //tells fish to hide at destCave
	//sets Cave home to destCave
	//calls setup_destination() function
	//sets state to 'z' for zooming
	//prints

	void float_in_place(); //tells fish to stop moving, eating, or hiding
	//sets state to 'f' for floating
	//prints

	void show_status(); //prints status of object

	double get_speed(); //returns speed of fish
	//speed = (1/size)(energy)*5
};

#endif

