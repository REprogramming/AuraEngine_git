#include <SFML/Graphics.hpp>
#include "AuraEngine.h"


static std::vector<GameObject*> listOfGameObjects;

int main()
{	
	if (AuraEngine::initialize()) 
	{
		AuraEngine::start();
	}

	system("pause");	
	return 0;
}

