#include <SFML/Graphics.hpp>
#include "AuraEngine.h"

int main()
{		

	if (AuraEngine::initialize()) {
		AuraEngine::start();
	}

	system("pause");	

	return 0;
}

