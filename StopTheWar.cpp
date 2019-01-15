
#include "SFML/Graphics.hpp"
#include "Objects/Bar.h"
#include "GameControllers\define.h"
#include "GameControllers\ResourcesManager.h"
#include "GameControllers\SceneManager.h"
#include "GameControllers\GameScene.h"
#include "Animation.h"
int main()
{

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	window.setFramerateLimit(LIMIT_FPS);

	ResourcesManager::getInstance()->LoadResource();
	Scene *test;
	test = new GameScene();
	test->Init();
	SceneManager::GetInstance()->ReplaceScene(test);

	while (window.isOpen())
	{		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		//	if (event.type == sf::Event::MouseMoved)
				
			//	SceneManager::GetInstance()->GetCurrentScene()->Event(event);
			if (event.type == sf::Event::MouseButtonPressed)
	
				SceneManager::GetInstance()->GetCurrentScene()->Event(event);

			if (event.type == sf::Event::KeyPressed||event.type == sf::Event::KeyReleased)
			{
				SceneManager::GetInstance()->GetCurrentScene()->Event(event);
			}

		}
		SceneManager::GetInstance()->Update(1.0 / LIMIT_FPS);

		window.clear(sf::Color(0, 200, 255, 0));

		SceneManager::GetInstance()->Render(window);

		window.display();
	}
	
		

	return 0;
}
