/*
 * Screen.cpp
 *
 *  Created on: 8 May 2023
 *      Author: home
 */

#include "Screen.h"

namespace particleExplosion {

	Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {}

	bool Screen::init() {

		if(SDL_Init(SDL_INIT_VIDEO) < 0) {
			return false;
		}

		m_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		// If SDL_CreateWindow() fails to create a window, it will return a NULL value.
		if (m_window == NULL) {
			SDL_Quit();
			return false;
		}

		// Create renderer and texture pointers:
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);


		// Error checks on creation of renderer and texture:
		if (m_renderer == NULL) {
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		if (m_texture == NULL) {
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		// Need to allocate enough memory for each pixel in the screen.
		// Uint32 is a SDL2 data type that is equivalent to 32 bits (approx the size of an int) - this matches the 8 bits set aside for each RGBA value for each pixel.
		m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

		memset(m_buffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
		memset(m_buffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

		return true;
	}

	// Loops through every pixel and changes the colour value of each pixel based on hexadecimal codes:
	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

		// This ensures that the function will not set pixels that are off the edge of the screen:
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
			return;
		}

		Uint32 colour = 0;  // 0x00000000

		colour += red; // 0x000000RR
		colour <<= 8;  // 0x0000RR00
		colour += green;  // 0x0000RRGG
		colour <<= 8;  // 0x00RRGG00
		colour += blue;  // 0x00RRGGBB
		colour <<= 8;  // 0xRRGGBB00
		colour += 0xFF;  // 0xRRGGBBFF

		m_buffer1[(y * SCREEN_WIDTH) + x] = colour;
	}

//	void Screen::clear() {
//		// Sets the RGBA values for all pixels in the screen (either in RGB or hexadecimal values) to be the same colour, in this case white:
//		memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
//	}

	void Screen::update() {
		SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH * sizeof(Uint32));  // Copy pixels to the texture;
		SDL_RenderClear(m_renderer);  // Clear existing render;
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);  // Copy texture over to render;
		SDL_RenderPresent(m_renderer);  // Update screen with new render;
	}

	void Screen::boxBlur() {
		// Swap the buffers so pixel info is in m_buffer2 and we are drawing to m_buffer1:
		Uint32 *temp = m_buffer1;
		m_buffer1 = m_buffer2;
		m_buffer2 = temp;

		// Iterate through every pixel on the screen:
		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			for (int x = 0; x < SCREEN_WIDTH; x++) {

				int redTotal = 0;
				int greenTotal = 0;
				int blueTotal = 0;

				// Iterate through the bits in a square surrounding the pixel at position x, y:
				for (int row = -1; row <= 1; row++) {
					for (int col = -1; col <= 1; col++) {
						int xCurrent = x + col;
						int yCurrent = y + row;

						// For each pixel in this square that is still on the screen, get the colour:
						if (xCurrent >= 0 && xCurrent < SCREEN_WIDTH && yCurrent >=0 && yCurrent < SCREEN_HEIGHT) {
							Uint32 colour = m_buffer2[(yCurrent * SCREEN_WIDTH) + xCurrent];

							Uint8 red = colour >> 24;
							Uint8 green = colour >> 16;
							Uint8 blue = colour >> 8;

							redTotal += red;
							greenTotal += green;
							blueTotal += blue;
						}
					}
				}

				Uint8 red = redTotal / 9;
				Uint8 green = greenTotal / 9;
				Uint8 blue = blueTotal / 9;

				setPixel(x, y, red, green, blue);
			}
		}
	}

	bool Screen::processEvents() {
		SDL_Event event;

		// Loop that will continue to run whilst there are outstanding events to be processed, with the argument entered as the address of the 'event' variable of type SDL_Event:
		while(SDL_PollEvent(&event)) {

			// Checks if an SDL_QUIT event (e.g. clicking the cross on the window) has been raised. If it has, it sets the quit bool to be true so the outer loop will stop.
			if(event.type == SDL_QUIT) {
				return false;
			}
		}

		return true;
	}

	void Screen::close() {
		delete [] m_buffer1;
		delete [] m_buffer2;
		SDL_DestroyTexture(m_texture);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

} /* namespace particleExplosion */
