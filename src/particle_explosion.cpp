//============================================================================
// Name        : particle_explosion.cpp
// Author      : Louise Cuthbertson
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// Using SDL 2 library as a GUI API. SDL2 was installed in terminal by typing "brew install sdl2"

#include <iostream>
#include "Screen.h"

using namespace std;
using namespace particleExplosion;

int main() {

	Screen screen;

	if (!screen.init()) {
		cout << "Error initialising SDL." << endl;
	}

	while (true) {
		// Update particles
		// Draw particles
		// Check for messages / events

		if (!screen.processEvents()) {
			break;
		}
	}

	screen.close();

	cout << "Program has ended." << endl;

	return 0;
}
