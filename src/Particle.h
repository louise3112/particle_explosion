/*
 * particle.h
 *
 *  Created on: 9 May 2023
 *      Author: home
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particleExplosion {

	// A struct is the same as a class. The only difference is that a struct's member variables are public by default; a classes member variables are private by default.
	struct Particle {

		double m_x;
		double m_y;

		// Sets the x and y speeds between -1 and 1 based on cartesian coordinates:
//		double m_xSpeed;
//		double m_ySpeed;
	private:
		// Sets the speed and direction based on polar coordinates:
		double m_speed;
		double m_direction;

	private:
		void init();

	public:
		Particle();
		void update(int interval);
		virtual ~Particle();
	};

} /* namespace particleExplosion */

#endif /* PARTICLE_H_ */
