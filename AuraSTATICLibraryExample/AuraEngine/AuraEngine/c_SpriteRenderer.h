#pragma once
#include "c_BaseComponent.h"

namespace Aura {
	class c_SpriteRenderer : public c_BaseComponent
	{
	public:
		c_SpriteRenderer();
		~c_SpriteRenderer();

		void draw();
		void update(const sf::RenderWindow* ptr_gameWindow);
	};

}

