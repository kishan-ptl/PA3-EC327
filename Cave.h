#ifndef CAVE_H
#define CAVE_H
#include "GameObject.h"
#include "Fish.h"
using namespace std;

class Fish;
class Cave : public GameObject
{
private:
	double space; //amount of space left in cave
public:
	Cave(); //initializes space to 100, display_code to 'c', state to 'e'

	//initializes id number to in_id, location to in_loc, + default constructor.
	Cave(int in_id, CartPoint in_loc) ;

	~Cave();

	bool hide_fish(Fish* fish_to_hide);
	//checks for space in cave
	//checks if fish is already hidden
	//attempts to hide fish 
	//updates available space if fish hides
	//returns true if hides fish

	bool release_fish(Fish* fish_to_release);
	//checks if fish is hidden
	//releases fish if hidden
	//updates space
	//returns true if releases fish

	bool update();
	//if cave space = 0, sets state to 'p' (packed) and display_code to 'C'
	//prints "Cave <id_num> is packed"
	//returns true

	void show_status();
	//prints out status of the object
};

#endif