#include <iostream>
#include "Model.h"
#include "CartPoint.h"
using namespace std;

Model::Model()
{
	time = 0;

	object_ptrs[0] = cave_ptrs[0] = new Cave(1, CartPoint(5, 1));
	object_ptrs[1] = cave_ptrs[1] = new Cave(2, CartPoint(6, 2));
	object_ptrs[2] = fish_ptrs[0] = new Fish(1, cave_ptrs[0]);
	object_ptrs[3] = fish_ptrs[1] = new Fish(2, cave_ptrs[1]);
	object_ptrs[4] = reef_ptrs[0] = new CoralReef(1, CartPoint(1, 20));
	object_ptrs[5] = reef_ptrs[1] = new CoralReef(2, CartPoint(20, 1));
	object_ptrs[6] = reef_ptrs[2] = new CoralReef(3, CartPoint(20, 20));

	num_objects = 7;
	num_fish = 2;
	num_reefs = 3;
	num_caves = 2;

	cout << "Model default constructed" << endl;
}

Model::~Model()
{
	for (int i = 0; i < num_objects; i++)
	{
		delete object_ptrs[i];
	}

	cout << "Model destructed" << endl;
}

//Model::Model(Model &model) {}

Fish* Model::get_Fish_ptr(int id_num)
{
	if (id_num > 0 && id_num <= num_fish)
	{
		return fish_ptrs[id_num - 1];
	}
	else return NULL;
		
}

CoralReef* Model::get_CoralReef_ptr(int id_num)
{
	if (id_num > 0 && id_num <= num_reefs)
	{
		return reef_ptrs[id_num - 1];
	}
	else return NULL;
}

Cave* Model::get_Cave_ptr(int id_num)
{
	if (id_num > 0 && id_num <= num_caves)
	{
		return cave_ptrs[id_num - 1];
	}
	else return NULL;
}

bool Model::update()
{
	time++; //increment time
	int events = 0;

	for (int i = 0; i < num_objects; i++)
	{
		if (object_ptrs[i]->update())
			events++; 
	}
	if (events > 0)
		return true;
	else return false;
}

void Model::display(View& view)
{
	cout << "Time: " << time << endl;
	view.clear();
	for (int i = 0; i < num_objects; i++)
	{
		view.plot(object_ptrs[i]);
	}
	view.draw();
}

void Model::show_status()
{
	for (int i = 0; i < num_objects; i++)
		object_ptrs[i] -> show_status();
}

int Model::get_time()
{
	return time;
}













