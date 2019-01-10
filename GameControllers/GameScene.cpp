#pragma once
#include "GameScene.h"

GameScene::GameScene()
{
	m_bar1 = new Bar(0,200,RenderGameObject::Direction::LEFT);
	m_bar2 = new Bar(300, 300, RenderGameObject::Direction::RIGHT);
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
		Monster* monster = NULL;
		if (rand() % 2 == 0)
		{

		
		 monster = new SpecialMonster(posX, posY, direction);
		monster->SetTwoBar(m_bar1 , m_bar2);
		}
		else
		{
			 monster = new NormalMonster(posX, posY, direction);
			if (direction==RenderGameObject::Direction::DOWN) monster->SetBar(m_bar1);
			else monster->SetBar(m_bar2);
		}
		m_listMonster.push_back(monster);
		srand((int)monster);
		m_timeAddMonster = (rand()%6)/2.0;
		m_currentTime = 0;
	}
	else
	{
		m_currentTime += deltime;
	}
}

void GameScene::Init()
{
	m_textFont = new sf::Font();
	m_textFont->loadFromFile("Resources/Fonts/arial.ttf");
	m_score = new sf::Text();
	m_score->setFont(*m_textFont);
	m_score->setString("Score: ");
	m_score->setPosition(SCREEN_WIDTH/2-50, SCREEN_HEIGHT/2-50);
}

void GameScene::Render(sf::RenderWindow &rd)
{
	for each (Monster* monster in m_listMonster)
	{
		monster->Render(rd);
	}
	m_bar1->Render(rd);
	m_bar2->Render(rd);

	m_score->setPosition(150, 150);
	//rd.draw(*m_score);
	
}
