#include <iostream>
#include <array>
#include <Windows.h>
#include "Cell.h"
#include "FuncPack.h"
using namespace std;

#define bijela 219
#define siva 176
#define crna ' '

int main() {
	ShowConsoleCursor(0);
	array<array<Cell, 100>, 30> cell_arr, cell_arr_input;
	
	randomize(cell_arr, cell_arr_input);
	while (true) life_cycle(cell_arr, cell_arr_input);
}