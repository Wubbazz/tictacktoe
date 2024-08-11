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
	}
}


int main()
{
	running = setup_window();
	
	while (running) {
		get_input();
	}

	return 0;
}
