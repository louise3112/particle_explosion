/*
 * Swarm.cpp
 *
 *  Created on: 9 May 2023
 *      Author: home
 */

#include "Swarm.h"

namespace particleExplosion {

	Swarm::Swarm(): lastTime(0) {
		m_pParticles = new Particle[NPARTICLES];

	}

	Swarm::~Swarm() {
		delete [] m_pParticles;
	}

	void Swarm::update(int msElapsed) {

		int interval = msElapsed - lastTime;

		for (int i = 0; i < NPARTICLES; i++) {
			m_pParticles[i].update(interval);
		}

		lastTime = msElapsed;
	}

} /* namespace particleExplosion */
