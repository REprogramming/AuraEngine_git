#include "c_Asteroid.h"
#include "SFML\Graphics.hpp"
#include <time.h>


c_Asteroid::c_Asteroid()
{
	// Create the Asteroid
	isDrawable == true; 
	_asteroid.setFillColor(sf::Color::Green);
	
	_asteroid.setRadius(rand() % 50 + 20);
	_asteroid.setPosition(rand() % 800 + 10, rand() % 600 + 10);
}

c_Asteroid::~c_Asteroid()
{
}

void c_Asteroid::draw()
{	
	
}

void c_Asteroid::update(sf::RenderWindow* ptr_gameWindow)
{
	std::cout << "Updating Asteroid" << std::endl;	
	ptr_gameWindow->draw(_asteroid);	

	// Random on/off 
	if (dirRandom == false)
	{
		randomNumber = rand() % 2;	
		dirRandom == true; 
	}
	else
	{
		
	}
		

	switch (randomNumber)
	{
		// MOVEMENT 		
		if (dirRandom == false)
		{
			case 0:		
				_asteroid.move(0.0, 1.0 * -1.0);
				break; 

			case 1:
				_asteroid.move(1.0 * -1.0, 1.0 );
				break; 

			case 2:
				_asteroid.move(0.0, 1.0);
				break; 				
		}
	}


	; 
	
}


