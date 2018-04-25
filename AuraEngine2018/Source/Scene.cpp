#include "Scene.h"
#include "AuraEngine.h"



Scene::Scene()
{
	
}


Scene::~Scene()
{
}

void Scene::onStart(int someScene)
{
	if (someScene == 0)
	{
		
		std::cout << "Loading all game assets..." << std::endl;			
		for (int i = 0; i < 8; i++)
		{
			// Create Asteroids
			std::cout << std::endl;
			GameObject objAsteroid; 
			objAsteroid.addComponent(GameObject::TRANSFORM);
			objAsteroid.addComponent(GameObject::RIGIDBODY);
			objAsteroid.addComponent(GameObject::ASTEROID);	
			objAsteroid.addComponent(GameObject::SPRITE_RENDERER);

			GameObjManager::listOfGameObjs.push_back(objAsteroid);			
		}		
	}	
	
}

void Scene::run(int someScene)
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "LOST GALAXIES");
	window.setFramerateLimit(60);	

	sf::Clock clock;

	sf::CircleShape mPlayer;
	mPlayer.setRadius(40.0f); 
	mPlayer.setPosition(100.f, 100.f); 
	mPlayer.setFillColor(sf::Color::Cyan); 		
	
	while (AuraEngine::isRunning || window.isOpen())
	{
		// TODO: Setting the clock/timeStep
		sf::Time elapsed = clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			
			switch (someScene)
			{
				case 0: // Splash Scene
				{			
					sf::Texture titleTexture;
					sf::Texture playButton;
					if (!titleTexture.loadFromFile("../assets/textures/lostGalaxiesTitle.jpg") || !playButton.loadFromFile("../assets/textures/playButton.png"))
					{
						std::cout << "Error: A texture has not been found." << std::endl;
						return;
					}

					sf::Sprite sprite(titleTexture);
					sf::Sprite sprite2(playButton);
					sprite2.scale(0.75, 0.75);
					sprite2.setPosition(0, 610);					

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						// Transform the mouse position from window coordinates to world coordinates.
						sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));					
						sf::FloatRect bounds = sprite2.getGlobalBounds();					
						if (bounds.contains(mouse))
						{												
							window.close();
							AuraEngine::sceneManager[1]->run(1);						
							AuraEngine::SceneStates currentScene = AuraEngine::GAMESCREEN;
						}
					}
					window.clear();
					window.draw(sprite);
					window.draw(sprite2);
					window.display();
				}
				break;

				case 1: // Game Scene
				{				
					window.setTitle("LOST GALAXIES - GAME SCREEN");						
					Scene::physicsEnabled = true; 
										
					while (AuraEngine::isRunning)
					{
						// *** Clearing the Screen ***
						window.clear();

						// *** Updating all gameObjects and their components! ***
						for (unsigned int i = 0; i < GameObjManager::listOfGameObjs.size(); i++)
						{
							
							GameObjManager::listOfGameObjs[i].update(&window);											
						}

						// *** Drawing all gameObjects to Screen ***
						window.draw(mPlayer);
						window.display();

						// Input 			
						mPlayer.getPosition();
						sf::Vector2f currentPosition = mPlayer.getPosition();
						{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
							currentPosition.y -= 8.0f;
							mPlayer.setPosition(currentPosition.x, currentPosition.y);
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
						{
							currentPosition.y += 8.0f;
							mPlayer.setPosition(currentPosition.x, currentPosition.y);
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						{
							currentPosition.x -= 8.0f;
							mPlayer.setPosition(currentPosition.x, currentPosition.y);
						}

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{
							currentPosition.x += 8.0f;
							mPlayer.setPosition(currentPosition.x, currentPosition.y);
						}
					
										
					}	
				
					break;
				}
				case 2: // End Screen
					break; 
				case 3: // Win screen

				default: 
					break; 
			}
		}
	}		
}

void Scene::end(int nextScreen)
{
}





