#include "c_Audio.h"
#include <SFML/Audio.hpp>

namespace Aura {
	c_Audio::c_Audio()
	{

	}


	c_Audio::~c_Audio()
	{
	}

	void c_Audio::playMusic(int scene)
	{
		switch (scene)
		{
		case 0: // SPLASH SCENE

			break;
		case 1: // GAME SCENE

			break;
		case 2:
			break;
		}
	}

	void c_Audio::stopMusic(int scene)
	{
	}

	void c_Audio::setVolume(int scene)
	{
	}

}

