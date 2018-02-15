#pragma once
#include<vector>
#include "GameObject.h"

class GameObjManager
{
public:
	GameObjManager();
	~GameObjManager();

	std::vector<GameObject> listOfGameObjs;
};

