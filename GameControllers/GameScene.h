#pragma once
#include "Scene.h"
#include "../Objects/Bar.h"
#include "../NormalMonster.h"
#include "../SpecialMonster.h"
#include "define.h"
#include <list>
class GameScene :public Scene
{
private:
	Bar* m_bar1;
	Bar* m_bar2;
	std::list<Monster*> m_listMonster;
	float m_currentTime = 0;
	float m_timeAddMonster = 0;

	int m_lastMouseMoveX, m_lastMouseMoveY;



public:
	GameScene();
	~GameScene();
	virtual void Update(float deltime);
	virtual void Event(sf::Event event);
	virtual void Init();
	virtual void Render(sf::RenderWindow&);

};