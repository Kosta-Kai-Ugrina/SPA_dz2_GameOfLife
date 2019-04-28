#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <array>
#include "Cell.h"
using namespace std;


void ShowConsoleCursor(bool showFlag);
void randomize(array<array<Cell, 100>, 30>& arr_orig, array<array<Cell, 100>, 30>& arr_input);
void renew_cell_state(array<array<Cell, 100>, 30>& arr_input, short row, short column, short state_counter);
void check_neighbor_state(array<array<Cell, 100>, 30>& arr_orig, array<array<Cell, 100>, 30>& arr_input);
void display(array<array<Cell, 100>, 30>& arr_orig);
void life_cycle(array<array<Cell, 100>, 30>& arr_orig, array<array<Cell, 100>, 30>& arr_input);