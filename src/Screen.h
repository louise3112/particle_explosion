/*
 * Screen.h
 *
 *  Created on: 8 May 2023
 *      Author: home
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace particleExplosion {

	class Screen {
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HEIGHT = 600;

	private:  // The m_ indicates that these are instance variables, rather than local variables
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer1;
		Uint32 *m_buffer2;

	public:
		Screen();
		bool init();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void boxBlur();
		void update();
		bool processEvents();
		void close();
	};

} /* namespace particleExplosion */

#endif /* SCREEN_H_ */
