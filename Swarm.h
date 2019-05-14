#pragma once

#include "Particle.h"

namespace asebaq {

	class Swarm
	{

	private:
		Particle * m_pParticles;
		int lastTime;

	public:
		const static int NPARTICLES = 7000;

		const Particle * const getParticles() { return m_pParticles; };
		void update(int elapsed);
		Swarm();
		virtual ~Swarm();
	};
}