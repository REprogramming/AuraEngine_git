#include "Asteroid.h"
#include <ctime>

namespace Aura {
	Asteroid::Asteroid()
	{
		//srand(time(0));
		mAsteroid.setFillColor(sf::Color::Red);

		radius = rand() % 80 + 20;
		positionX = rand() % 500 + 10;
		positionY = rand() % 500 + 10;

		mAsteroid.setRadius(radius);
		mAsteroid.setPosition(positionX, positionX);

		//addComponent(GameObject::TRANSFORM); 
		//addComponent(GameObject::RIGIDBODY); 	
	}


	Asteroid::~Asteroid()
	{

	}

	sf::CircleShape Asteroid::draw()
	{
		mAsteroid.move(0, -5);
		return mAsteroid;
	}

	void Asteroid::c_update()
	{
	}


}
