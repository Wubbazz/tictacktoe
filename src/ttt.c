#include "ttt.h"

char turn = 'x';
static char grid_array [3][3] = {{'1', '2', '3'},
								 {'4', '5', '6'},
								 {'7', '8', '9'}};
static int turn_count = 0;

bool check_win_scenario()
{
	/*
	*   [-][-][-]
	*   [ ][ ][ ]
	*   [ ][ ][ ]
	*    
	*/
	if (grid_array[0][0] == grid_array[0][1] && grid_array[0][1] == grid_array[0][2])
	{
		return true;
	}
	/*
	*   [ ][ ][ ]
	*   [-][-][-]
	*   [ ][ ][ ]
	*    
	*/
	if (grid_array[1][0] == grid_array[1][1] && grid_array[1][1] == grid_array[1][2])
	{
		return true;
	}
	/*
	*   [ ][ ][ ]
	*   [ ][ ][ ]
	*   [-][-][-]
	*    
	*/
	if (grid_array[2][0] == grid_array[2][1] && grid_array[2][1] == grid_array[2][2])
	{
		return true;
	}
   	/*
	*   [|][ ][ ]
	*   [|][ ][ ]
	*   [|][ ][ ]
	*    
	*/
	if (grid_array[0][0] == grid_array[1][0] && grid_array[1][0] == grid_array[2][0])
	{
		return true;
	}
	/*
	*   [ ][|][ ]
	*   [ ][|][ ]
	*   [ ][|][ ]
	*    
	*/
	if (grid_array[0][1] == grid_array[1][1] && grid_array[1][1] == grid_array[2][1])
	{
		return true;
	}
	/*
	*   [ ][ ][|]
	*   [ ][ ][|]
	*   [ ][ ][|]
	*    
	*/
	if (grid_array[0][2] == grid_array[1][2] && grid_array[1][2] == grid_array[2][2])
	{
		return true;
	}
	/*
	*   [\][ ][ ]
	*   [ ][\][ ]
	*   [ ][ ][\]
	*    
	*/
	if (grid_array[0][0] == grid_array[1][1] && grid_array[1][1] == grid_array[2][2])
	{
		return true;
	}
	/*
	*   [ ][ ][/]
	*   [ ][/][ ]
	*   [/][ ][ ]
	*    
	*/
	if (grid_array[0][2] == grid_array[1][1] && grid_array[1][1] == grid_array[2][0])
	{
		return true;
	}

	return false;
}
bool draw_check()
{
	if (turn_count == 9) {
		printf("No one won :(\n");
		return true;
	}
	return false;
}
bool update_grid_array(int i1, int i2)
{
	if (grid_array[i1][i2] != 'x' && grid_array[i1][i2] != 'o') {
		if (i1 <= 2 && i2 <= 2 && i1 >= 0 && i2 >= 0) {
			grid_array[i1][i2] = turn;
		}
		turn_count++;
		if (turn == 'x') {
			turn = 'o';
		} else if (turn == 'o'){
			turn = 'x';
		}
		return true;
	}
	return false;
}
