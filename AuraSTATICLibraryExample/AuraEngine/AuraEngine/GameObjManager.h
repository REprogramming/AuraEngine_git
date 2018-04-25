#pragma once
#include <vector>
#include "Scene.h"
#include "GameObject.h"

namespace Aura {
	class GameObjManager
	{
	public:
		GameObjManager();
		~GameObjManager();

		static int gameObjectIDs;

		static std::vector<GameObject> listOfGameObjs;
		static void addObj(GameObject someObject);
	};



}
