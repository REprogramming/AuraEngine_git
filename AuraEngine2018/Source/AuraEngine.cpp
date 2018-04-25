#include "AuraEngine.h"



bool AuraEngine::isRunning = false;
AuraEngine::gameEngineRequirements AuraEngine::gameRequirements;
std::map<int, Scene*> AuraEngine::sceneManager;
AuraEngine::SceneStates currentScene = AuraEngine::SPLASHSCREENSCENE; 



void AuraEngine::displaySplashScreen()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "AURA GAME ENGINE 2018");
	window.setFramerateLimit(30);

	sf::Texture splashTexture;
	if (!splashTexture.loadFromFile("../assets/textures/auraSplash.jpg"))
	{
		std::cout << "Splash texture not found" << std::endl;
		return;
	}

	sf::Sprite sprite(splashTexture);
	sprite.setScale(0.5f, 0.5f);
	window.clear();
	window.draw(sprite);
	window.display();


}

bool AuraEngine::initialize()
{
	displaySplashScreen();
	gameRequirements.CPU_REQUIRED = 1500;
	gameRequirements.GPU_REQUIRED = 100;
	gameRequirements.STORAGE_REQUIRED = 1000; 
	gameRequirements.PHYSICAL_RAM_NEEDED = 100; 
	gameRequirements.VIRTUAL_RAM_NEEDED = 100; 

	std::cout << "Starting initialize..." << std::endl;
	isRunning = false;

	gameEngineRequirements;
	if (!checkStorage())
		return false;

	if (!checkAvailMemory())
		return false;

	if (!checkCPU())
		return false;

	return true; 
	
}




void AuraEngine::start()
{
	std::cout << std::endl;
	std::cout << "********************" << std::endl;
	std::cout << "Starting Aura Engine" << std::endl;
	buildAllScenes();
	AuraEngine::SPLASHSCREENSCENE;
	AuraEngine::isRunning = true; 
	gameStart(); 
	gameLoop();

}




	
bool AuraEngine::checkStorage()
{
	int const DRIVE = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(DRIVE, &diskfree);
	unsigned __int64 const neededClusters = gameRequirements.STORAGE_REQUIRED / (diskfree.sectors_per_cluster*diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters) {
		std::cout << "CheckStorage Failure: Not enough physical storage." << std::endl;
		return false;
	}
	std::cout << "Storage check successful." << std::endl;
	return true;
}

bool AuraEngine::checkAvailMemory()
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&status);
	DWORDLONG totalVirtualMem = status.ullTotalPageFile;

	DWORDLONG totalPhysMemAvail = status.ullTotalPhys;
	DWORDLONG physMemUsed = status.ullTotalPhys - status.ullAvailPhys;

	if (status.ullTotalPhys < gameRequirements.PHYSICAL_RAM_NEEDED) {
		std::cout << "Memory Failure: Not enough physical memory" << std::endl;
		return false;
	}

	if (status.ullAvailVirtual < gameRequirements.VIRTUAL_RAM_NEEDED) {
		std::cout << "CheckMemory Failure: Not enough virtual memory." << std::endl;
		return false;
	}

	char *buff = new char(gameRequirements.VIRTUAL_RAM_NEEDED);
	if (buff) {
		delete[] buff;
	}
	else {
		std::cout << "CheckMemory Failure: Not enough contiguous memory." << std::endl;
		return false;
	}
	std::cout << "Total physical memory (RAM) available: " << totalPhysMemAvail << " Total Virtual memory available: " << totalVirtualMem << std::endl;
	std::cout << "Memory check successful." << std::endl;
	return true;
}

	bool AuraEngine::checkCPU()
	{		
		std::cout << "Checking CPU..." << std::endl;
		
		char Buffer[_MAX_PATH];
		DWORD BufSize = sizeof(DWORD);
		DWORD dwMHZ = 0;
		DWORD type = REG_DWORD;
		HKEY hKey;
		DWORD stringType = REG_SZ;
		char charArray[MAX_PATH];

		long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

		if (lError != ERROR_SUCCESS)
		{
			FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, NULL, lError, 0, Buffer, _MAX_PATH, 0);
			return false;
		}
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHZ, &BufSize);
		
		if (dwMHZ > gameRequirements.CPU_REQUIRED)
		{
			std::cout << "CPU SPEED (MHz): " << dwMHZ << std::endl;

			long cError = RegQueryValueEx(hKey, "ProcessorNameString", NULL, &stringType, (LPBYTE)&charArray, &BufSize);
			while (cError == ERROR_MORE_DATA) {
				BufSize++;
				cError = RegQueryValueEx(hKey, "ProcessorNameString", NULL, &stringType, (LPBYTE)&charArray, &BufSize);
			}
			std::cout << charArray << std::endl;
			std::cout << "CPU check successful. " << dwMHZ << "MHz" << std::endl;
		}
		else 
		{
			std::cout << "INSUFFICENT CPU SPEED REQUIREMENTS." << std::endl; 
		}		
		
		return dwMHZ;		
	}

	void AuraEngine::gameStart()
	{		
		switch (currentScene)
		{
			case SPLASHSCREENSCENE:
			{
				AuraEngine::sceneManager[0]->onStart(0);
				break;
			}			
			
		}
		
	}

	void AuraEngine::gameLoop()
	{	
			switch (currentScene)
			{
				case SPLASHSCREENSCENE:
				{						
					AuraEngine::sceneManager[0]->run(0);					
					break;
				}
				case GAMESCREEN:
				{
					AuraEngine::sceneManager[1]->run(1);
					break;
				}
				case LOSESCREEN:
				{
					AuraEngine::sceneManager[2]->run(2);
					break;
				}
				case WINSCREEN:
				{
					AuraEngine::sceneManager[3]->run(3);
				}
				
			}
		}
	
		








	void AuraEngine::buildAllScenes()
	{
		std::cout << "Building all scenes." << std::endl; 

		AuraEngine::sceneManager.insert(std::make_pair(0, new Scene()));
		AuraEngine::sceneManager.insert(std::make_pair(1, new Scene()));
		AuraEngine::sceneManager.insert(std::make_pair(2, new Scene()));
		AuraEngine::sceneManager.insert(std::make_pair(3, new Scene()));

		AuraEngine::sceneManager[0]->sceneName = "SplashScene";
		AuraEngine::sceneManager[0]->ID = 0; 	
		AuraEngine::sceneManager[0]->physicsEnabled = false; 

		AuraEngine::sceneManager[0]->sceneName = "GameScene";
		AuraEngine::sceneManager[0]->ID = 1;
		AuraEngine::sceneManager[0]->physicsEnabled = false;

		AuraEngine::sceneManager[0]->sceneName = "LoseScene";
		AuraEngine::sceneManager[0]->ID = 2;
		AuraEngine::sceneManager[0]->physicsEnabled = false;

		AuraEngine::sceneManager[0]->sceneName = "WinScene";
		AuraEngine::sceneManager[0]->ID = 3;
		AuraEngine::sceneManager[0]->physicsEnabled = false;

	}
