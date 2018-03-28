#include "GameObjManager.h"


std::vector<GameObject*> GameObjManager::listOfGameObjs;
int GameObjManager::gameObjectIDs = 0; 

GameObjManager::GameObjManager()
{
}

GameObjManager::~GameObjManager()
{
}

void GameObjManager::addObj(GameObject &someObject)
{
	std::cout << "Obj added to GameObjManager." << std::endl; 
	GameObjManager::listOfGameObjs.push_back(&someObject);
}

void GameObjManager::removeObj(GameObject &someObject, int someID)
{
	for (int i = 0; i < GameObjManager::listOfGameObjs.size(); i++)
	{
		if (someID == GameObjManager::listOfGameObjs[i]->ID); 
		{
			// destroy/delete game object
		}
	}	
}
