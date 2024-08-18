#include <stdio.h>
#include <SDL2/SDL.h>
#include "display.h"
#include "ttt.h"
bool running = false;


void draw_x_or_o(int x, int y)
{
	int size = 100;
	if (turn == 'x') {
		draw_x(x, y, size);
	} else {
		draw_circle(x, y, size);
	}
}

void check_pos_and_update(int x, int y)
{
	int line_border_1 = 299;
	int line_border_2 = 599;
	int line_border_3 = 899;
	if (x < line_border_1 && y < line_border_1) {
		if (update_grid_array(0,0)) {
			draw_x_or_o(line_border_1/2, line_border_1/2);
		}
	}
	if (x > line_border_1 && x < line_border_2 && y < line_border_1) {
		if (update_grid_array(0,1)) {
			draw_x_or_o((line_border_2 + line_border_1)/2, line_border_1/2);
		}
	}
	if (x > line_border_2 && y < line_border_1) {
		if (update_grid_array(0,2)) {
			draw_x_or_o((line_border_2 + line_border_3)/2, line_border_1/2);
		}
	}
	if (x < line_border_1 && y < line_border_2 && y > line_border_1) {
		if (update_grid_array(1,0)) {
			draw_x_or_o(line_border_1/2, (line_border_1 + line_border_2)/2);
		}
	}
	if (x > line_border_1 && x < line_border_2 && y > line_border_1 && y < line_border_2) {
		if (update_grid_array(1,1)) {
			draw_x_or_o((line_border_2 + line_border_1)/2, (line_border_1 + line_border_2)/2);
		}
	}
	if (x > line_border_2 && x < line_border_3 && y > line_border_1 && y < line_border_2) {
		if (update_grid_array(1,2)) {
			draw_x_or_o((line_border_2 + line_border_3)/2, (line_border_1 + line_border_2)/2);
		}
	}
	
	if (x < line_border_1 && y < line_border_3 && y > line_border_2) {
		if (update_grid_array(2,0)) {
			draw_x_or_o(line_border_1/2, (line_border_2 + line_border_3)/2);
		}
	}
	
	if (x > line_border_1 && x < line_border_2 && y < line_border_3 && y > line_border_2) {
		if (update_grid_array(2,1)) {
			draw_x_or_o((line_border_2 + line_border_1)/2, (line_border_2 + line_border_3)/2);
		}
	}
	
	if (x > line_border_2 && x < line_border_3 && y < line_border_3 && y > line_border_2) {
		if (update_grid_array(2,2)) {
			draw_x_or_o((line_border_2 + line_border_3)/2, (line_border_2 + line_border_3)/2);
		}
	}	
}

void get_input(void)
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			running = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (SDL_BUTTON_LEFT == event.button.button) {
				int x, y;
				SDL_GetMouseState(&x,&y);
				check_pos_and_update(x,y);
			}
	}
}


void render()
{
	render_color_buffer();
	SDL_RenderPresent(renderer);
}
int main()
{
	running = setup_window();
	// Sets the background of the window grey	
    clear_color_buffer();
	setup_grid();
	while (running) {
		get_input();
		if (check_win_scenario()) {
			printf("The winner is %c!!!!\n", turn);
			SDL_Delay(3000);
			running = false;
		}
		render();
	}
	
	destroy_display();
	return 0;
}
