#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"

extern SDL_Window * window;
extern SDL_Renderer * renderer;

bool setup_window(void);



#endif

