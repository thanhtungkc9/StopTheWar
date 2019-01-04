#pragma once
#include "GameScene.h"

GameScene::GameScene()
{
	m_bar1 = new Bar(0,300,RenderGameObject::Direction::LEFT);
	m_bar2 = new Bar(300, 200, RenderGameObject::Direction::RIGHT);
}

GameScene::~GameScene()
{

}
void GameScene::Event(sf::Event eventt)
{
	if (eventt.type== sf::Event::MouseMoved)
		m_bar1->GetSprite()->setPosition(eventt.mouseMove.x,m_bar1->GetSprite()->getPosition().y);
}
void GameScene::Update(float deltime)
{
	
	m_bar1->Update(deltime);
	m_bar2->Update(deltime);
	for (std::list<Monster*>::iterator monster = m_listMonster.begin(); monster != m_listMonster.end();)
	{
		(*monster)->Update(deltime);
		if ((*monster)->GetSprite()->getPosition().y <= -200 || (*monster)->GetSprite()->getPosition().y > SCREEN_HEIGHT+300)
		{
			std::list<Monster*>::iterator tmp = monster;
			monster++;
			m_listMonster.erase(tmp);
			continue;		
		}
		monster++;
	}
	if (m_currentTime >= m_timeAddMonster)
	{
		float posX, posY;
		Bar* tmp;
		int direction = RenderGameObject::Direction::DOWN;
		direction = -2 + 4 * (rand() % 2);
		if (direction == RenderGameObject::Direction::DOWN)
		{
			posY = -200 + rand() % 100;
			tmp = m_bar2;
		}
		else
		{
			posY = SCREEN_HEIGHT + 200 - rand() % 100;
			tmp = m_bar1;
		}
		posX = rand() % SCREEN_WIDTH - 100;
		Monster* monster = new Monster(posX, posY, direction);
		monster->SetBar(tmp);
		m_listMonster.push_back(monster);
		m_timeAddMonster = 1.5f;
		m_currentTime = 0;
	}
	else
	{
		m_currentTime += deltime;
	}
}

void GameScene::Init()
{

}

void GameScene::Render(sf::RenderWindow &rd)
{
	for each (Monster* monster in m_listMonster)
	{
		monster->Render(rd);
	}
	m_bar1->Render(rd);
	m_bar2->Render(rd);
	
}
