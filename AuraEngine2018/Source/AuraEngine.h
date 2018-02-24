
#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <direct.h>

#include "GameObjManager.h"
class GameObjManager; 



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
								
		struct gameEngineRequirements
		{
			float CPU_REQUIRED;
			float GPU_REQUIRED; 
			float STORAGE_REQUIRED; 
			float PHYSICAL_RAM_NEEDED;
			float VIRTUAL_RAM_NEEDED; 
		};
	
		static gameEngineRequirements gameRequirements;


		// Create GameObjManager - Scene Graph
		static GameObjManager fullScene;
};
