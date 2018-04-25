#pragma once
#include "c_BaseComponent.h"

class c_SpriteRenderer : public c_BaseComponent
{
public:
	c_SpriteRenderer();
	~c_SpriteRenderer();

	void draw(); 
	void update(sf::RenderWindow* ptr_gameWindow);
};

