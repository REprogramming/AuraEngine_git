#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

namespace Aura {
	class c_BaseComponent
	{
	public:

		c_BaseComponent();
		bool isDrawable = false;
		virtual ~c_BaseComponent();
		virtual void update(sf::RenderWindow* ptr_gameWindow);


	protected:
	private:
	};
}


