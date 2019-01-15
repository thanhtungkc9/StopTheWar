#pragma once
#include "GameScene.h"
GameScene::GameScene()
{
	m_bar1 = new Bar(0,275,RenderGameObject::Direction::LEFT);
	m_bar2 = new Bar(300, 425, RenderGameObject::Direction::RIGHT);


	m_timeAddBlackArmy = 1.0;
}

GameScene::~GameScene()
{

}
void GameScene::Event(sf::Event eventt)
{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_bar1->SetMovingRight(true);
			m_bar1->SetMovingLeft(false);

			m_bar2->SetMovingRight(false);
			m_bar2->SetMovingLeft(true);
		}
		else
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_bar1->SetMovingRight(false);
			m_bar1->SetMovingLeft(true);

			m_bar2->SetMovingRight(true);
			m_bar2->SetMovingLeft(false);
		}
		else
		{
			m_bar1->SetMovingRight(false);
			m_bar1->SetMovingLeft(false);

			m_bar2->SetMovingRight(false);
			m_bar2->SetMovingLeft(false);
		}
		
	if (eventt.type == sf::Event::MouseButtonPressed)
	{
		RenderGameObject *newArmy = new Army_Shotgun();
		newArmy->Init();
		newArmy->SetDirection(RenderGameObject::Direction::DOWN);
		newArmy->SetPosition(eventt.mouseButton.x, eventt.mouseButton.y);
		m_gameMap->AddArmy(newArmy);
	}

}
void GameScene::Update(float deltime)
{	
	m_bar1->Update(deltime);
	m_bar2->Update(deltime);

	m_gameMap->Update(deltime);
	

	if (m_currentTime >= m_timeAddBlackArmy)
	{
		RenderGameObject *newArmy=new Army_Shotgun();		
		newArmy->Init();
		srand((int)newArmy);
		int TopOrBottom = rand() % 2;
		newArmy->SetPosition(newArmy->GetSpriteAnim()->getGlobalBounds().width/2+ newArmy->GetSpriteAnim()->getGlobalBounds().width*(rand()% ARMY_NUM_LANE ), 
			TopOrBottom*(SCREEN_HEIGHT+100)-50);
		if (TopOrBottom == 0)//Top
		{			
			newArmy->SetDirection(RenderGameObject::Direction::DOWN);
		}
		else	//Bottom		
		{		
			newArmy->SetDirection(RenderGameObject::Direction::UP);
		}
		m_gameMap->AddArmy(newArmy);
		m_currentTime = 0;
	}
	else
	{
		m_currentTime += deltime;
	}
	CheckCollision();
	
}

void GameScene::Init()
{
	m_textureBackGround = ResourcesManager::getInstance()->GetTexture(eID::TOP_LANE_BACKGROUND);
	m_spriteBackGround = new sf::Sprite();
	m_spriteBackGround->setTexture(*m_textureBackGround);
	m_spriteBackGround->setScale((float) SCREEN_WIDTH / m_spriteBackGround->getLocalBounds().width, (float) SCREEN_HEIGHT / m_spriteBackGround->getLocalBounds().height);


	m_textFont = new sf::Font();
	m_textFont->loadFromFile("Resources/Fonts/arial.ttf");
	m_score = new sf::Text();
	m_score->setFont(*m_textFont);
	m_score->setString("Score: "+ std::to_string(GameGlobal::getInstance()->GetScore()));

	m_score->setPosition(SCREEN_WIDTH/2-50, SCREEN_HEIGHT/2-50);


	m_gameMap = new GameMap();
	GameTime::GetInstance()->StartCounter();

	

}

void GameScene::Render(sf::RenderWindow &rd)
{	
	rd.draw(*m_spriteBackGround);
	m_bar1->Render(rd);
	m_bar2->Render(rd);
	
	m_gameMap->Render(rd);
	
	//float timee = GameTime::GetInstance()->GetTimeInSecond() - GameTime::GetInstance()->GetStartTime();
	//m_score->setString("time: "+ std::to_string(timee));

	m_score->setString("Score: " + std::to_string(GameGlobal::getInstance()->GetScore()));
	m_score->setPosition(150, 150);
	rd.draw(*m_score);
	
}

void GameScene::CheckCollision()
{
	std::list<RenderGameObject*> listArmy = m_gameMap->GetListArmy();
	for (std::list<RenderGameObject*>::iterator it = listArmy.begin(); it != listArmy.end();it++ )
	{
		if ((*it)->GetSpriteAnim()->getGlobalBounds().intersects(m_bar1->GetSprite()->getGlobalBounds()))
		{
			(*it)->Collision(m_bar1);
			m_bar1->Collision((*it));
		}
		if ((*it)->GetSpriteAnim()->getGlobalBounds().intersects(m_bar2->GetSprite()->getGlobalBounds()))
		{
			(*it)->Collision(m_bar2);
			m_bar2->Collision((*it));
		}
		for (std::list<RenderGameObject*>::iterator it1 = listArmy.begin(); it1 != listArmy.end(); it1++)
		{
			if (*it1 != *it && (*it1)->GetSpriteAnim()->getGlobalBounds().intersects((*it)->GetSpriteAnim()->getGlobalBounds()))
			{
				(*it)->Collision(*it1);
				(*it1)->Collision(*it);
			}
		}
	}
	std::list<Bullet*> listArmyBullet = m_gameMap->GetListArmyBullet();
	for (std::list<Bullet*>::iterator bullet = listArmyBullet.begin(); bullet != listArmyBullet.end(); bullet++)
	{
		if ((*bullet)->GetSpriteAnim()->getGlobalBounds().intersects(m_bar1->GetSprite()->getGlobalBounds()))
		{
			(*bullet)->Collision(m_bar1);
			m_bar1->Collision((*bullet));
		}
		if ((*bullet)->GetSpriteAnim()->getGlobalBounds().intersects(m_bar2->GetSprite()->getGlobalBounds()))
		{
			(*bullet)->Collision(m_bar2);
			m_bar2->Collision((*bullet));
		}
		for (std::list<RenderGameObject*>::iterator army = listArmy.begin(); army != listArmy.end(); army++)
		{
			if ((*bullet)->GetSpriteAnim()->getGlobalBounds().intersects((*army)->GetSpriteAnim()->getGlobalBounds()))
			{
				if (abs((*bullet)->GetPosition().y - (*army)->GetPosition().y) <= (*army)->GetAnimation()->GetSprite()->getGlobalBounds().height / 2.0)
				{
					(*army)->Collision((*bullet));
					(*bullet)->Collision((*army));
				}
			}
		}
	}
}

