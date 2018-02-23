#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <direct.h>

#include "GameObjManager.h"

class AuraEngine
{

public: 
	
	static void start(); 
	static bool initialize(); 
	static bool checkStorage();
	static bool checkCPU(); 
	static bool checkAvailMemory(); 
	static void gameLoop();
	static void displaySplashScreen(); 
	static bool isRunning; 	
	static GameObjManager _gameObjectManager;
		

	struct gameEngineRequirements
	{
		float CPU_REQUIRED;
		float GPU_REQUIRED; 
		float STORAGE_REQUIRED; 
		float PHYSICAL_RAM_NEEDED;
		float VIRTUAL_RAM_NEEDED; 
	};
	
	static gameEngineRequirements gameRequirements;
};
