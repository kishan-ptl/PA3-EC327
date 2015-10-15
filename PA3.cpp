#include <iostream>
#include "CartPoint.h"
#include "CartVector.h"
#include "GameObject.h"
#include "CoralReef.h"
#include "Cave.h"
#include "Fish.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
using namespace std;

int main()
{
	char command;
	Model model;
	View view;
	model.show_status();

	do{
	model.display(view);
	cout << "Enter command: " << endl;
	cin >> command;

	switch (command)
	{
		case 's' :
			do_swim_command(model);
			break;
		case 'e' :
			do_eat_command(model);
			break;
		case 'f' :
			do_float_command(model);
			break;
		case 'z' :
			do_zoom_command(model);
			break;
		case 'g' :
			do_go_command(model);
			break;
		case 'r' :
			do_run_command(model);
			break;
	}
}while(command != 'q');

return 0;
}



