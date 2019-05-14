#pragma once

namespace asebaq {

	struct Particle
	{
		// Public
		// x and y coordinates for the particle
		double m_x;
		double m_y;
		// Constructor and Destructor
		Particle();
		virtual ~Particle();
		// update method
		void update(int interval);

	private:
		// Particle speed and dirction(polar coordinates)
		double m_speed;
		double m_direction;
		// Initiation method
		void init();		
	};
}
