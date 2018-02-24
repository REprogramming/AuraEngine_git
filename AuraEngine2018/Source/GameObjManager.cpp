#include "GameObjManager.h"


void GameObjManager::start()
{
	for (std::vector<GameObject*>::iterator it = AuraEngine::sceneGraph.listOfObjs.begin(); it != AuraEngine::sceneGraph.listOfObjs.end(); it++)
	{
		(*it)->start(); // call each GameObjects start()
	}
}

void GameObjManager::update()
{		
	for (std::vector<GameObject*>::iterator it = AuraEngine::sceneGraph.listOfObjs.begin(); it != AuraEngine::sceneGraph.listOfObjs.end(); it++) 
	{
		(*it)->update(); // call each GameObjects update()
	}	
}

void GameObjManager::addObj(GameObject* someObj)
{
	AuraEngine::sceneGraph.listOfObjs.push_back(someObj);
}


