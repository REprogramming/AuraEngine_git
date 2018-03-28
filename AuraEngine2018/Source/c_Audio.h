#pragma once

#include <map>
#include <string>

#include "c_BaseComponent.h"

class c_Audio: public c_BaseComponent
{
public:
	c_Audio();
	~c_Audio();

	void playMusic(int scene); 
	void stopMusic(int scene); 
	void setVolume(int scene); 	

};

