#pragma once

#include<iostream>
#include<vector>
#include<cstdlib>

#include "c_BaseComponent.h"


class c_Asteroid : public c_BaseComponent
{
public:
	c_Asteroid();
	virtual ~c_Asteroid();
	
	sf::CircleShape _asteroid;	
		
	void draw();
	void update(sf::RenderWindow* ptr_gameWindow);

private: 
	float radius;
	float speed;
	float positionX;
	float positionY;

	bool dirRandom = false; 
	int randomNumber; 
};

