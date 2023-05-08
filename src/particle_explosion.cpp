//============================================================================
// Name        : particle_explosion.cpp
// Author      : Louise Cuthbertson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Using SDL 2 library as a GUI API. SDL2 was installed in terminal by typing "brew install sdl2"

#include <iostream>
#include <math.h>
#include "Screen.h"

using namespace std;
using namespace particleExplosion;

int main() {

	Screen screen;

	if (!screen.init()) {
		cout << "Error initialising SDL." << endl;
	}

	int max = 0;

	while (true) {
		// Update particles


		// Draw particles:
		int msElapsed = SDL_GetTicks();
		unsigned char red = (1 + sin(msElapsed * 0.001)) * 128;
		unsigned char green = (1 + sin(msElapsed * 0.002)) * 128;
		unsigned char blue = (1 + sin(msElapsed * 0.003)) * 128;

		if (green > max) {
			max = green;
		}

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}

		// Draw the screen:
		screen.update();

		// Check for messages / events:
		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();

	cout << "Program has ended." << endl;

	return 0;
}
