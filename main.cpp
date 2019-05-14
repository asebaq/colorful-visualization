#include <iostream>
#include <SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"

using namespace std;
using namespace asebaq;

int main(int argc, char* argv[]) {

	// Generate random numbers
	srand(time(NULL));

	Screen screen;

	// Make sure that the screen initiated 
	if (screen.init() == false) {
		cout << "Error initializing SDL" << endl;
	}
	
	Swarm swarm;

	while (true) {
		// Draw and update particles
		// Calculate the time from the beginig of the program
		int elapsed = SDL_GetTicks();

		// Clear the screen
		swarm.update(elapsed);

		// Changing the RGB values for the color of the pixels
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);

		// Get the particles of the screen
		const Particle * const pParticles = swarm.getParticles();

		// Set particles position and color
		for (int i = 0; i < Swarm::NPARTICLES; i++) {

			Particle particle = pParticles[i];
			// Position
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;
			// Color
			screen.setPixel(x, y, red, green, blue);

		}		

		// Blurring the screen
		screen.boxBlur();

		// Draw the screen
		screen.update();

		// Check massage/events
		if (screen.processEvents() == false) {
			break;
		}	
	}

	// Close the screen
	screen.close();

	return 0;
}
