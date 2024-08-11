#include <stdio.h>
#include <SDL2/SDL.h>
#include "display.h"


int main()
{
	printf("Hello world\n");
	bool running = setup_window();
	SDL_Delay(3000);
	return 0;
}
