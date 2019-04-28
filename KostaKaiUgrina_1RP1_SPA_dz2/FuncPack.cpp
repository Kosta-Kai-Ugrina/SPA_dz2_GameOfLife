#include "FuncPack.h"
#include <iostream>


// OVO SAM MAZNUO S INTERNETA I SLUZI SKRIVANJU KURSORA
void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void randomize(array<array<Cell, 100>, 30>& arr_orig, array<array<Cell, 100>, 30>& arr_input)
{
	srand(time(NULL));
	for (short row = 0; row < arr_input.max_size(); row++)
		for (short column = 0; column < arr_input[0].max_size(); column++)
		{
			int rng = rand() % 4;
			if (rng == 0) arr_input[row][column].set_state(1);
		}
	arr_orig = arr_input;
}

void renew_cell_state(array<array<Cell, 100>, 30>& arr_input, short row, short column, short state_counter)
{
	if (state_counter > 3) arr_input[row][column].set_state(0);
	else if (state_counter < 2) arr_input[row][column].set_state(0);
	if (state_counter == 3) arr_input[row][column].set_state(1);
}

void check_neighbor_state(array<array<Cell, 100>, 30>& arr_orig, array<array<Cell, 100>, 30>& arr_input)
{
	for (short row = 0; row < arr_orig.max_size(); row++)
		for (short column = 0; column < arr_orig[0].max_size(); column++)
		{
			short state_counter = 0;
			//provjera gornjeg lijevog ruba
			if (row==0 && column==0)
			{
				if (arr_orig[0][1].is_alive()) ++state_counter;
				if (arr_orig[1][0].is_alive()) ++state_counter;
				if (arr_orig[1][1].is_alive()) ++state_counter;
			}
			//provjera donjeg lijevog ruba
			else if (row == arr_orig.max_size()-1 && column==0)
			{
				if (arr_orig[arr_orig.max_size() - 2][0].is_alive()) ++state_counter;
				if (arr_orig[arr_orig.max_size() - 2][1].is_alive()) ++state_counter;
				if (arr_orig[arr_orig.max_size() - 1][1].is_alive()) ++state_counter;
			}
			// provjera gornjeg desnog ruba
			else if (row == 0 && column == arr_orig[0].max_size() - 1)
			{
				if (arr_orig[0][arr_orig[0].max_size() - 2].is_alive()) ++state_counter;
				if (arr_orig[1][arr_orig[0].max_size() - 2].is_alive()) ++state_counter;
				if (arr_orig[1][arr_orig[0].max_size() - 1].is_alive()) ++state_counter;
			}
			//provjera donjeg desnog ruba
			else if (row == arr_orig.max_size() - 1 && column == arr_orig[0].max_size() - 1)
			{
				if (arr_orig[arr_orig.max_size() - 2][arr_orig[0].max_size() - 2].is_alive()) ++state_counter;
				if (arr_orig[arr_orig.max_size() - 2][arr_orig[0].max_size() - 1].is_alive()) ++state_counter;
				if (arr_orig[arr_orig.max_size() - 1][arr_orig[0].max_size() - 2].is_alive()) ++state_counter;
			}
			//provjera gornje margine
			else if (row==0)
			{
				if (arr_orig[0][column - 1].is_alive()) ++state_counter;
				if (arr_orig[0][column + 1].is_alive()) ++state_counter;
				if (arr_orig[1][column - 1].is_alive()) ++state_counter;
				if (arr_orig[1][column + 0].is_alive()) ++state_counter;
				if (arr_orig[1][column + 1].is_alive()) ++state_counter;
			}
			//provjera donje margine
			else if (row == arr_orig.max_size() - 1) 
			{
				if (arr_orig[arr_orig.max_size() - 2][column - 1].is_alive()) ++state_counter;
				if (arr_orig[arr_orig.max_size() - 2][column + 0].is_alive()) ++state_counter;
				if (arr_orig[arr_orig.max_size() - 2][column + 1].is_alive()) ++state_counter;
				if (arr_orig[arr_orig.max_size() - 1][column - 1].is_alive()) ++state_counter;
				if (arr_orig[arr_orig.max_size() - 1][column + 1].is_alive()) ++state_counter;
			}
			//provjera lijeve margine
			else if (column == 0)
			{
				if (arr_orig[row - 1][0].is_alive()) ++state_counter;
				if (arr_orig[row - 1][1].is_alive()) ++state_counter;
				if (arr_orig[row + 0][1].is_alive()) ++state_counter;
				if (arr_orig[row + 1][0].is_alive()) ++state_counter;
				if (arr_orig[row + 1][1].is_alive()) ++state_counter;
			}
			//provjera desne margine
			else if (column == arr_orig[0].max_size() - 1)
			{
				if (arr_orig[row - 1][arr_orig[0].max_size() - 2].is_alive()) ++state_counter;
				if (arr_orig[row - 1][arr_orig[0].max_size() - 1].is_alive()) ++state_counter;
				if (arr_orig[row + 0][arr_orig[0].max_size() - 2].is_alive()) ++state_counter;
				if (arr_orig[row + 1][arr_orig[0].max_size() - 2].is_alive()) ++state_counter;
				if (arr_orig[row + 1][arr_orig[0].max_size() - 1].is_alive()) ++state_counter;
			}
			//provjera svega ostalog
			else
			{
				if (arr_orig[row - 1][column - 1].is_alive()) ++state_counter;
				if (arr_orig[row - 1][column + 0].is_alive()) ++state_counter;
				if (arr_orig[row - 1][column + 1].is_alive()) ++state_counter;
				if (arr_orig[row + 0][column - 1].is_alive()) ++state_counter;
				if (arr_orig[row + 0][column + 1].is_alive()) ++state_counter;
				if (arr_orig[row + 1][column - 1].is_alive()) ++state_counter;
				if (arr_orig[row + 1][column + 0].is_alive()) ++state_counter;
				if (arr_orig[row + 1][column + 1].is_alive()) ++state_counter;
			}
			//promjena stanja na kopiji polja
			renew_cell_state(arr_input, row, column, state_counter);
		}
	//sinkroniziranje polja
	arr_orig = arr_input;

}

void display(array<array<Cell, 100>, 30>& arr_orig)
{
	system("cls");
	for (short row = 0; row < arr_orig.max_size(); row++)
	{
		for (short column = 0; column < arr_orig[0].max_size(); column++) arr_orig[row][column].output_color();
		std::cout << std::endl;
	}
}

void life_cycle(array<array<Cell, 100>, 30>& arr_orig, array<array<Cell, 100>, 30>& arr_input)
{
	check_neighbor_state(arr_orig, arr_input);
	display(arr_orig);
	Sleep(50);
}
