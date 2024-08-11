#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"

extern SDL_Window * window;
extern SDL_Renderer * renderer;
extern int window_width;
extern int window_height;

bool setup_window(void);



#endif

