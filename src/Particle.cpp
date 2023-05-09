/*
 * particle.cpp
 *
 *  Created on: 9 May 2023
 *      Author: home
 */

#include "Particle.h"
#include <stdlib.h>
#include <math.h>

namespace particleExplosion {

	// x & y values are initialised at 0 to ensure particles start at the centre of the screen and explode outwards:
	Particle::Particle(): m_x(0), m_y(0) {
		init();
	}

	void Particle::init() {

		m_x = 0;
		m_y = 0;

		// Sets the direction (in radians) and speed:
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = (0.04 * rand()) / RAND_MAX;

		// Increase the distance between particles to change the distribution and make it less blocky:
		m_speed *= m_speed;

		// Sets the x and y speeds between -1 and 1 based on cartesian coordinates:
		// m_xSpeed = 0.01 * (((2.0 * rand()) / RAND_MAX) - 1);
		// m_ySpeed = 0.01 * (((2.0 * rand()) / RAND_MAX) - 1);
	}

	void Particle::update(int interval) {

		// Give a curl effect to the direction:
		m_direction += interval * 0.0004;

		// The update function for polar coordinates:
		double xSpeed = m_speed * cos(m_direction);
		double ySpeed = m_speed * sin(m_direction);

		m_x += xSpeed * interval;
		m_y += ySpeed * interval;

		// When particles go off the edge of the screen, they will be re-initialised at the centre of the screen:
		if (m_x < -1.0 || m_x > 1.0 || m_y < -1.0 || m_y > 1.0) {
			init();
		}

		// A random particle in every 100 will be reinitialised:
		if (rand() < RAND_MAX / 100) {
			init();
		}

		// The update function for x and y based on cartesian coordinates:
		// m_x += m_xSpeed;
		// m_y += m_ySpeed;

		// If the particle falls off the edge of the screen, we negate it's speed so it moves in the opposite direction:
		// if (m_x < -1.0 || m_x >= 1.0) {
		//  	m_xSpeed = -m_xSpeed;
		// }

		// if (m_y < -1.0 || m_y >= 1.0) {
		//  	m_ySpeed = -m_ySpeed;
		// }
	}

	Particle::~Particle() {}

} /* namespace particleExplosion */
