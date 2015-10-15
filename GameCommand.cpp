#include <iostream>
#include "GameCommand.h"
#include "CartPoint.h"
#include "Fish.h"
using namespace std;

void do_swim_command(Model& model)
{
	int id;
	double x,y;
	cin >> id >> x >> y;
	model.get_Fish_ptr(id)->start_swimming(CartPoint(x,y));
	return;
}

void do_go_command(Model& model)
{
	cout << "Advancing one tick..." << endl;
	model.update();
	model.show_status();
	return;
}

void do_run_command(Model& model)
{
	int i = 0;
	while((!model.update()) && i < 4)
	{
		i++;
	}
	return;
}

void do_eat_command(Model& model)
{
	int id1, id2;
	cin >> id1 >> id2;
	model.get_Fish_ptr(id1)->start_eating(model.get_CoralReef_ptr(id2));
	return;
}

void do_float_command(Model& model)
{
	int id;
	cin >> id;
	model.get_Fish_ptr(id)->float_in_place();
	return;
}

void do_zoom_command(Model& model)
{
	int id1, id2;
	cin >> id1 >> id2;
	model.get_Fish_ptr(id1)->start_hiding(model.get_Cave_ptr(id2));
	return;
}
