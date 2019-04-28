#pragma once
#include <iostream>
using namespace std;

#define bijela 219
#define crna ' '


class Cell
{
private:
	bool state;
	char color;
public:
	Cell();
	void set_state(bool state);
	bool is_alive();
	void output_color();

};

