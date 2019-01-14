#pragma once
#include "GameScene.h"

GameScene::GameScene()
{
	m_bar1 = new Bar(0,275,RenderGameObject::Direction::LEFT);
	m_bar2 = new Bar(300, 425, RenderGameObject::Direction::RIGHT);


	m_timeAddBlackArmy = 2.0;
}

GameScene::~GameScene()
{

}
void GameScene::Event(sf::Event eventt)
{
	if (eventt.type == sf::Event::MouseMoved)
	{
		m_bar1->GetSprite()->setPosition(eventt.mouseMove.x - m_bar1->GetSprite()->getGlobalBounds().width / 2, m_bar1->GetSprite()->getPosition().y);
		m_bar2->GetSprite()->setPosition(SCREEN_WIDTH- eventt.mouseMove.x - m_bar2->GetSprite()->getGlobalBounds().width / 2, m_bar2->GetSprite()->getPosition().y);
	}

}
void GameScene::Update(float deltime)
{	
	m_bar1->Update(deltime);
	m_bar2->Update(deltime);

	for (std::list<RenderGameObject*>::iterator it = m_listBlackArmy.begin(); it != m_listBlackArmy.end(); )
	{
		if ((*it)->GetStatus()!=RenderGameObject::Status::DEAD)
		(*it)->Update(deltime);
		else
		{
			RenderGameObject* tmp = *it;
			it++;
			m_listBlackArmy.remove(tmp);
			delete tmp;
			
			continue;
		}
		it++;
	}
	

	if (m_currentTime >= m_timeAddBlackArmy)
	{
		RenderGameObject *newBlackArmy=new Army_Knife();		
		newBlackArmy->Init();
		std::cout << m_listBlackArmy.size();
		newBlackArmy->SetPosition(newBlackArmy->GetSpriteAnim()->getGlobalBounds().width/2+ newBlackArmy->GetSpriteAnim()->getGlobalBounds().width*(rand()% ARMY_NUM_LANE ), SCREEN_HEIGHT+25);
		m_listBlackArmy.push_back(newBlackArmy);
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
	m_textFont = new sf::Font();
	m_textFont->loadFromFile("Resources/Fonts/arial.ttf");
	m_score = new sf::Text();
	m_score->setFont(*m_textFont);
	m_score->setString("Score: ");
	m_score->setPosition(SCREEN_WIDTH/2-50, SCREEN_HEIGHT/2-50);

	GameTime::GetInstance()->StartCounter();

}

void GameScene::Render(sf::RenderWindow &rd)
{	
	m_bar1->Render(rd);
	m_bar2->Render(rd);
	
	for (std::list<RenderGameObject*>::iterator it = m_listBlackArmy.begin(); it != m_listBlackArmy.end(); it++)
	{
		(*it)->Render(rd);
	}
	
	float timee = GameTime::GetInstance()->GetTimeInSecond() - GameTime::GetInstance()->GetStartTime();

	m_score->setString("time: "+ std::to_string(timee));
	m_score->setPosition(150, 150);
	//rd.draw(*m_score);
	
}

void GameScene::CheckCollision()
{
	for (std::list<RenderGameObject*>::iterator it = m_listBlackArmy.begin(); it != m_listBlackArmy.end();it++ )
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

	}
}