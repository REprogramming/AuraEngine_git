// LostGalaxy.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <windows.h>
#include <direct.h>
#include <map>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Config.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <AuraEngine\AuraEngine.h>
#include <AuraEngine\GameObject.h>
#include <AuraEngine\TestLib.h>
#include <AuraEngine\Scene.h>
#include <AuraEngine\GameObjManager.h>

using namespace Aura;

static std::vector<Aura::GameObject*> listOfGameObjects;




int main()
{
	// * TESTING AURA STATIC LIB
	double a = 9.0; 
	double b = 1.0; 
	std::cout << "Testing Aura Engine (VS Static Library): " << std::endl << std::endl;
	std::cout << "Total is : " << Aura::TestLib::Add(a, b) << std::endl; 
	
	//// * ACTUAL GAME		
	/*if (Aura::AuraEngine::initialize())
	{
		Aura::AuraEngine::start();		
	}*/

	system("pause"); 
    return 0;

}








