#include "AuraEngine.h"


// Static variables - predefined
bool AuraEngine::isRunning;
AuraEngine::gameEngineRequirements AuraEngine::gameRequirements;
GameObjManager AuraEngine::gameObjectManager;


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
	return false;
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
	
	

	void AuraEngine::start()
	{
		gameObjectManager.start();
		while (isRunning)
		{
			gameLoop();
		}
	}



	void AuraEngine::gameLoop()
	{
		sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML");
		window.setFramerateLimit(30);

		while (window.isOpen())
		{
			// handle events
			sf::Event event;

			/*while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}*/

			// update			
			gameObjectManager.update(); 
			window.clear();

			// draw objects
			window.display();
		}
	}

	