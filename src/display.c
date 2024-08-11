#include "display.h"

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;

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
		800,
		800,
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
