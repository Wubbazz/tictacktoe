#include "display.h"

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;
int window_width = 900;
int window_height = 900;

bool setup_window(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "ERROR: Could not initialize SDL");
		return false;
	}

	window = SDL_CreateWindow(
		"ticktactoe",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		window_width,
		window_height,
		SDL_WINDOW_SHOWN
	);

	if (window == NULL) {
		fprintf(stderr, "ERROR: Could not initialize SDL window");
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (renderer == NULL) {
		fprintf(stderr, "ERROR: Could not initialize SDL renderer");
		return false;
	}

	return true;
}

void destroy_display()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
