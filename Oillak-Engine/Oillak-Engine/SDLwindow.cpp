#include "SDLwindow.h"


SDLwindow::SDLwindow()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: %s\nz " << SDL_GetError() << std::endl;
	}
	else
	{
		//Create window
		wnd = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
		if (wnd == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(wnd);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(wnd);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}
}


SDLwindow::SDLwindow(int width, int height)
{
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialize! SDL_Error: %s\nz "<< SDL_GetError() << std::endl;
	}
	else
	{
		//Create window
		wnd = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (wnd == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(wnd);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(wnd);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}

}

SDLwindow::~SDLwindow()
{
	//Destroy window
	SDL_DestroyWindow(wnd);

	//Quit SDL subsystems
	SDL_Quit();
}
