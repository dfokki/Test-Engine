#pragma once
#include "Dependencies\SDL\include\SDL.h"
#include <iostream>
class SDLwindow
{
protected:
	int screen_width = 640;
	int screen_height = 480;
public:
	SDL_Window* wnd = NULL;
	SDL_Surface* screenSurface = NULL;
	SDLwindow(int width, int height);
	SDLwindow();
	~SDLwindow();
};

