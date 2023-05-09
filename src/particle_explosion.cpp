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
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace particleExplosion;

int main() {

	// Seed random number generator based on current time:
	srand(time(NULL));

	Screen screen;

	if (!screen.init()) {
		cout << "Error initialising SDL." << endl;
	}

	Swarm swarm;

	while (true) {
		// Update particles


		// Draw particles:
		int msElapsed = SDL_GetTicks();
		unsigned char red = (1 + sin(msElapsed * 0.0001)) * 128;
		unsigned char green = (1 + sin(msElapsed * 0.0002)) * 128;
		unsigned char blue = (1 + sin(msElapsed * 0.0003)) * 128;

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * (Screen::SCREEN_WIDTH / 2);
			int y = (particle.m_y + 1) * (Screen::SCREEN_HEIGHT / 2);

			screen.setPixel(x, y, red, green, blue);
		}

		// To set the colour of the whole screen:
//		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
//			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
//				screen.setPixel(x, y, red, green, blue);
//			}
//		}

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
