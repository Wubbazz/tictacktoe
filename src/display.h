#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"

extern SDL_Window * window;
extern SDL_Renderer * renderer;

bool setup_window(void);
void destroy_display(void);
void setup_grid(void);
void clear_color_buffer(void);
void render_color_buffer(void);
void draw_circle(int x0, int y0, int radius);
#endif

