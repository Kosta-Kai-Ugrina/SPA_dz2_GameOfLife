#include "Cell.h"



Cell::Cell()
{
	state = 0;
	color = crna;
}

void Cell::set_state(bool state) 
{ 
	this->state = state; 
	if (state) color = bijela;
	else color = crna;
}

bool Cell::is_alive() { return state; }

void Cell::output_color() { cout << color; }

