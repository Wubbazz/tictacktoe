#include "display.h"

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;
const int window_width = 900;
const int window_height = 900;
uint32_t * color_buffer = NULL;
SDL_Texture * color_buffer_texture = NULL;


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
	// Creating a texture buffer the size of the window width * window_height to hold the color values
	color_buffer = (uint32_t *) malloc(window_width * window_height * sizeof(uint32_t));	
	if (color_buffer == NULL) {
		fprintf(stderr, "ERROR: Could not create the color_buffer array");
		return false;
	}
	color_buffer_texture = SDL_CreateTexture(
		renderer,
	    SDL_PIXELFORMAT_ARGB8888,
		SDL_TEXTUREACCESS_STREAMING,
		window_width,
		window_height
	);

	if (color_buffer_texture == NULL) {
		fprintf(stderr, "ERROR: Could not create SDL texture");
		return false;
	}
	return true;
}

void clear_color_buffer()
{
	/*
	for (int i = 0; i < window_width * window_height; i++) {
		color_buffer[i] = 0xFFFF0000;
	}
	*/
	for (int y = 0; y < window_height; y++) {
		for (int x = 0; x < window_width; x++) {
			color_buffer[(y * window_width) + x] = 0xFF949494;
		}
	}
}
void render_color_buffer()
{
	SDL_UpdateTexture(
		color_buffer_texture,
		NULL,
		color_buffer,
		(int) (sizeof(uint32_t) * window_width)
	);
	SDL_RenderCopy(renderer, color_buffer_texture, NULL, NULL);
}

void setup_grid()
{

	for (int y = 0; y < window_height; y++) {
		for (int x = 0; x < window_width; x++) {
			// Drawing a pixel where the grid is split into vertical and horizontal lines
			// Based on the 900 x 900 grid and the relative color buffer positions
			/*	
			if (y == 299 || y == 599 || x == 299 || x == 599) {
				color_buffer[(y * window_width) + x] = 0xFF91D2FF;
			}
			*/
			if ((y < 304 && y > 294) || (y < 604 && y > 594) || (x < 304 && x > 294) || (x < 604 && x > 594)) {
				color_buffer[(y * window_width) + x] = 0xFF91D2FF;
			}
		}
	}
}
void destroy_display()
{
	free(color_buffer);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
