#include <iostream>
#include "GameObject.h"
using namespace std;

//initializes location to (0,0), display_code, and id_num
GameObject::GameObject(char in_code, int in_id)
{
	location.x = 0;
	location.y = 0;
	display_code = in_code;
	id_num = in_id;
	cout << "GameObject default constructed" << endl;
}

//initializes location, display_code, and id_num
GameObject::GameObject(char in_code, int in_id, CartPoint in_loc)
{
	location.x = in_loc.x;
	location.y = in_loc.y;
	display_code = in_code;
	id_num = in_id;
	cout << "GameObject constructed" << endl;
}

GameObject::~GameObject()
{
	cout << "GameObject destructed" << endl;
}

//returns location of GameObject
CartPoint GameObject::get_location()
{
	return location;
}

char GameObject::get_display_code()
{
	return display_code;
}

char GameObject::get_state()
{
	return state;
}
//returns ID of GameObject
int GameObject::get_id()
{
	return id_num;
}

//outputs information about GameObject
void GameObject::show_status()
{
	cout << display_code << " with ID " << id_num << " at location " << location << endl;
}

void GameObject::drawself(char* grid)
{
	*grid = display_code;
	char char_id = (char)(id_num + (int)'0');
	*(grid+1) = char_id;
}












