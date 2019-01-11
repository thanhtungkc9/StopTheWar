
#include "SFML/Graphics.hpp"
#include "Objects/Bar.h"
#include "Objects/Monster.h"
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
	//window.setFramerateLimit(30);

	ResourcesManager::getInstance()->LoadResource();
	Scene *test;
	test = new GameScene();
	test->Init();
	SceneManager::GetInstance()->ReplaceScene(test);
	
	Animation *body, *feet,*attack;

	body = new Animation(eID::BLACKARMY, 20, "blackarmy_knife_move", 0.35f);
	feet = new Animation(eID::BLACKARMY_WALK_FEET, 20, "blackarmy_walk_feet", 0.35f);
	attack = new Animation(eID::BLACKARMY_MELEE_ATTACK, 15, "blackarmy_knife_attack", 0.15f);

	feet->GetSprite()->setPosition(200, 200);
	body->GetSprite()->setPosition(200, 200);
	body->GetSprite()->setRotation(-90);
	feet->GetSprite()->setRotation(-90);

	attack->GetSprite()->setPosition(200, 400);
	attack->GetSprite()->setRotation(-90);

	body->GetSprite()->setScale(0.3, 0.3);
	feet->GetSprite()->setScale(0.3, 0.3);
	attack->GetSprite()->setScale(0.3, 0.3);
	while (window.isOpen())
	{		
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseMoved)
				//std::cout << "Mouse move x=" << event.mouseMove.x << "\t y=" << event.mouseMove.y<<"\n";
				SceneManager::GetInstance()->GetCurrentScene()->Event(event);
		}
		SceneManager::GetInstance()->Update(1.0 /30);

		body->Update(1.0 / 30);
		feet->Update(1.0 / 30);
		attack->Update(1.0 / 30);
		window.clear(sf::Color(0, 200, 255, 0));

		SceneManager::GetInstance()->Render(window);
		feet->Render(window);
		body->Render(window);
	

		attack->Render(window);

		window.display();
	}
	
		

	return 0;
}
