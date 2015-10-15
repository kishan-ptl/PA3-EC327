#include <iostream>
#include "Fish.h"
# include <cmath>
using namespace std;
//delta = (destination - location) * (speed / cart_distance(destination, location))

//within a step of the destination if...
//fabs(destination - location) < delta x & delta y

Fish::Fish() : GameObject('F',0)
{
	energy = 15;
	size = 10;
  state = 'h';
	prefeast_size = size;
	display_code = 'F';
	home = NULL;
	reef = NULL;
	destination = CartPoint();
  cout << "Fish default constructed" << endl;
}

Fish::Fish(int in_id, Cave* home) : GameObject('F', in_id, home -> get_location())
{
  size = 10; 
	energy = 15;
  this -> home = home;
  home->hide_fish(this);
  state = 'h';
	prefeast_size = size;
	display_code = 'F';
	reef = NULL;
	destination = CartPoint();
  cout << "Fish constructed" << endl;
}

Fish::~Fish()
{
  cout << "Fish destructed" << endl;
}

bool Fish::update_location()
{
	if ((fabs(destination.x - location.x)) <= fabs(delta.x) && (fabs(destination.y - location.y)) <= fabs(delta.y))
	{
		location = destination;
		cout << display_code << get_id() << ": I'm there!" << endl;
		return true;
	}
	else
	{
		location = location + delta;
		cout << display_code << get_id() << ": Just keep swimming..." << endl;
		return false;
	}
}

void Fish::setup_destination(CartPoint dest) //calculates delta
{
	destination = dest;
	delta = (destination - location)*(get_speed())/(cart_distance(destination, location));
	state = 's';
}

bool Fish::update() //if object is moving --> update_location();
{
	switch(state) 
	{
    case 'f' : return false;

    case 's' : 
    	if (update_location())
    	{
    		state = 'f';
    		return true;
    	}
    	else {return false;}

   	case 'o' : 
   		if (update_location())
   		{
        cout << display_code << get_id() << ": Starting to dine at a coral reef" << endl;
   			prefeast_size = size;
        state = 'e';
        return true;
   		}
   		else {return false;}

   	case 'e' : 
      if (reef->is_empty())
     		{
     			state = 'f';
     			cout << display_code << get_id() << ": This reef has no more food for me" << endl;
          return true;
     		}
   		else 
   		{
        size += (.5*(reef->provide_food()));
        cout << display_code << get_id() << ": Grew to size " << size << endl;
      }
      if (size >= 2*prefeast_size)
      {
        setup_destination(home->get_location());
        cout << display_code << get_id() << ": I'm full. I'm heading home " << endl;
        state = 'z';
        return true;
      }
      else
      {  
        return false;
      } 

   	case 'z' : 
   		if (update_location())
   		{
   			if (home->hide_fish(this))
   			{
   				state = 'h';
   				cout << display_code << get_id() << ": I am hidden and safe" << endl;
          return true;
   			}
   			else 
   			{ 
   				state = 'p'; 
   				cout << display_code << get_id() << ": Help! My home is full" << endl;
          return true;
   			}
      }
      else return false;

   	case 'h' : if (is_hidden())
   				{ 
            //home->hide_fish(this);
   					cout << display_code << get_id() << ": Is hidden in Cave " \
   					<< home->get_id() << endl;
            return false;
   				}
          else {return false;}

   	case 'p' : return false;

    default : return false;
	}
}

double Fish::get_size()
{
	return size;
}

void Fish::start_swimming(CartPoint dest)
{
  if (is_hidden())
  {
    home->release_fish(this);
  }
  destination = dest;
	setup_destination(destination);
	state = 's';
	cout << "Swimming " << get_id() << " to " << destination << endl;
  cout << display_code << get_id() << ": On my way" << endl;
}

void Fish::start_eating(CoralReef* destReef)
{
  if (is_hidden())
  {
    home->release_fish(this);
  }
	reef = destReef;
	setup_destination(reef->get_location());
	state = 'o';
	cout << "Fish " << get_id() << " eating at CoralReef " << reef->get_id() \
	<< " and returning back to Cave " << home->get_id() << endl;
	cout << display_code << get_id() << ": Food here I come" << endl;
}

bool Fish::is_hidden()
{
	if (state == 'h')
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void Fish::start_hiding(Cave* destCave)
{
  if (is_hidden())
  {
    home->release_fish(this);
  }
	home = destCave;
	setup_destination(home->get_location());
	state = 'z';
	cout << "Fish " << get_id() << " swimming to Cave " << home->get_id() << endl;
	cout << home->get_display_code() << home->get_id() << ": Off to safety" << endl;
}

void Fish::float_in_place()
{
	state = 'f';
	cout << "Stopping " << get_id() << endl;
	cout << display_code << get_id() << ": Resting my fins" << endl;
}

void Fish::show_status()
{

	switch(state) 
	{
    case 'f' : cout << "Fish status: " << display_code << " with ID " << get_id() \
    << " at location " << location << " Is Floating. Has a size of: " << size \
    << " And energy of: " << energy << endl;
  return;

 	case 's' : cout << "Fish status: " << display_code << " with ID " << get_id() \
    << " at location " << location << " Has speed of: " << get_speed() \
    << " And is heading to " << destination << endl;
  return;

 	case 'o' : cout << "Fish status: " << display_code << " with ID " << get_id() \
    << " at location " << location << " Is outbound to Reef: " << reef->get_id() \
    << " With a speed of " << get_speed() << endl;
  return;

 	case 'e' : cout << "Fish status: " << display_code << " with ID " << get_id() \
    << " at location " << location << " is eating at Reef " << reef->get_id() \
    << endl; 
  return;

 	case 'z' : cout << "Fish status: " << display_code << " with ID " << get_id() \
    << " at location " << location << " Is swimming to Cave " << home->get_id() \
    << " With a speed of " << get_speed() << endl;
  return;

  case 'h' : cout << "Fish status: " << display_code << " with ID " << get_id() \
  << " at location " << location << " is hidden in Cave " << home->get_id() << endl;
  return;

  case 'p' : cout << display_code << get_id() << ": Is panicked" << endl;
  return;
	}
}

double Fish::get_speed()
{
	return (1/size)*(energy)*5;
}



