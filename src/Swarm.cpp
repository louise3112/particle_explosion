/*
 * Swarm.cpp
 *
 *  Created on: 9 May 2023
 *      Author: home
 */

#include "Swarm.h"

namespace particleExplosion {

	Swarm::Swarm() {
		m_pParticles = new Particle[NPARTICLES];

	}

	Swarm::~Swarm() {
		delete [] m_pParticles;
	}

} /* namespace particleExplosion */
