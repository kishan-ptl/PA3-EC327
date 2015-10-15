#ifndef MODEL_H
#define MODEL_H
#include "GameObject.h"
#include "CoralReef.h"
#include "Cave.h"
#include "Fish.h"
#include "View.h"
using namespace std;
class View;
class Model
{
private:
	int time; 

	//each object will have a pointer in object_ptrs and appropiate other array.
	GameObject* object_ptrs[7];
	int num_objects; //7
	Fish* fish_ptrs[2];
	int num_fish; //2
	Cave* cave_ptrs[2];
	int num_caves; //2
	CoralReef* reef_ptrs[3];
	int num_reefs; //3

	Model(Model &); //copy constructor

public:
	//initializes time to 0, creates objects using 'new'
	Model(); //stores the pointers to objects in the arrays
	~Model();

	//iterates over fish_ptrs array and returns pointer that has id_num
	//if no Fish with id_num, returns NULL
	Fish* get_Fish_ptr(int id_num);

	CoralReef* get_CoralReef_ptr(int id_num);

	Cave* get_Cave_ptr(int id_num);

	//iterates through object_ptrs array and calls update() for each object
	bool update(); //increments time

	//outputs time and generates the view display for all of the GameObjects
	void display(View& view);

	void show_status(); //outputs status of all GameObjects by calling their show_status

	int get_time();
};


#endif
