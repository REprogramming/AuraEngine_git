#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <direct.h>
#include <map>

#include "Scene.h"





class AuraEngine
{

public: 
	
	static void start();

	static bool initialize(); 
	static bool checkStorage();
	static bool checkCPU(); 
	static bool checkAvailMemory(); 

	static void gameLoop();
	static void gameStart(); 
	static void displaySplashScreen(); 
	static bool isRunning; 

	static std::map<int, Scene*> sceneManager;
	static void buildAllScenes();	
	
	static enum SceneStates { SPLASHSCREENSCENE, GAMESCREEN, LOSESCREEN, WINSCREEN, };		

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
