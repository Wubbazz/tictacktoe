#include <stdio.h>
#include <SDL2/SDL.h>
#include "display.h"

bool running = false;

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
				draw_circle(x,y, 50);

			}
	}
}

void update()
{
}

void render()
{
	
	render_color_buffer();
	SDL_RenderPresent(renderer);
}
int main()
{
	running = setup_window();	
    clear_color_buffer();
	setup_grid();
	
	draw_circle(900/2, 900/2, 100);
	draw_line(900/2, 900/2, 900, 900);
	while (running) {
		get_input();
		update();
		render();
	}
	
	destroy_display();
	return 0;
}
