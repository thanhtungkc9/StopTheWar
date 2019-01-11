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
	m_bar1->Render(rd);
	m_bar2->Render(rd);

	m_score->setPosition(150, 150);
	//rd.draw(*m_score);
	
}
