#include <iostream>
#include "Cave.h"
using namespace std;

Cave::Cave() : GameObject('c',0)
{
	space = 100;
	state = 'e';
	cout << "Cave default constructed" << endl;
}

Cave::Cave(int in_id, CartPoint in_loc) : GameObject('c', in_id, location)
{
	location = in_loc;
	space = 100;
	state = 'e';
	cout << "Cave constructed" << endl;
}

Cave::~Cave()
{
	cout << "Cave destructed" << endl;
}

bool Cave::hide_fish(Fish* fish_to_hide)
{
	if (space >= fish_to_hide->get_size()) 
	{
		space = space - fish_to_hide->get_size();
		return true;
	}
	else 
	{
		return false;
	}
}

bool Cave::release_fish(Fish* fish_to_release)
{
	if (fish_to_release->state == 'h')
	{
		fish_to_release->state = 'f';
		space = space + fish_to_release->get_size();
		return true;
	}
	else 
	{
		return false;
	}
}

bool Cave::update()
{
	static bool alreadyempty = false;
	if (space == 0)
	{
		if (alreadyempty)
		{
			return false;
		}
		state = 'p';
		display_code = 'C';
		cout << "Cave " << get_id() << " is packed" << endl;
		alreadyempty = true;
		return true;
	}
	else
	{
		return false;
	}
}

void Cave::show_status()
{
	cout << "Cave Status: " << display_code << " with ID " << get_id() \
	<< " at location " << location << " has a space of " << space << endl;
}

