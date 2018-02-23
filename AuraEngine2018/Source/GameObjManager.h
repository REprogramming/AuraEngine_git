#pragma once
#include <iostream>
#include <stdio.h>
#include <map>
#include<vector>
#include <list>
#include <iterator>
#include "GameObject.h"

 class GameObjManager
{	

	public:
				
		static std::map<const int, GameObject*> listOfObjects;		
		static int objNumber; 

		GameObjManager();
		~GameObjManager();		
	
		void start();	
		void update();	
		
		
};

