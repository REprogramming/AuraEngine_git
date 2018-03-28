#pragma once
#include<vector>
#include "GameObject.h"

class GameObjManager
{
public:
	GameObjManager();
	~GameObjManager();

	static int gameObjectIDs;

	static std::vector<GameObject*> listOfGameObjs;
	static void addObj(GameObject &someObject); 
	static void removeObj(GameObject &someObject, int someID);
	
};

