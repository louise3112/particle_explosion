//============================================================================
// Name        : particle_explosion.cpp
// Author      : Louise Cuthbertson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Using SDL 2
// SDL2 was installed in terminal by typing "brew install sdl2"
#include <SDL.h>

#include <iostream>

using namespace std;

int main() {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed." << endl;
		return 1;
	}

	// Create an SDL_Window pointer called window, which is assigned to the value of SDL_CreateWindow function, called with the following arguments:
	//		"Particle Fire Explosion" - the title of the window;
	//		SDL_WINDOWPOS_UNDEFINED - a static SDL variable that allows us to have the SDL window position undefined (required twice for x & y axis positions);
	//		SCREEN_WIDTH & SCREEN_HEIGHT - const int values defined at the top of the program that set the windows size;
	//		SDL_WINDOW_SHOWN - tells the program to show the window on creation without any specific amendments.
	SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// If SDL_CreateWindow() fails to create a window, it will return a NULL value.
	if (window == NULL) {
		SDL_Quit();
		return 2;
	}

	bool quit = false;
	SDL_Event event;

	while (!quit) {
		// Update particles
		// Draw particles
		// Check for messages / events

		// Loop that will continue to run whilst there are outstanding events to be processed, with the argument entered as the address of the 'event' variable of type SDL_Event:
		while(SDL_PollEvent(&event)) {
			// Checks if an SDL_QUIT event (e.g. clicking the cross on the window) has been raised. If it has, it sets the quit bool to be true so the outer loop will stop.
			if(event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	cout << "Program has ended." << endl;

	return 0;
}
