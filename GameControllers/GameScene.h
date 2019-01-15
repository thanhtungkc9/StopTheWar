#pragma once
#include "Scene.h"
#include "../Objects/Bar.h"
#include "../Army_Knife.h"
#include "../Army_Shotgun.h"
#include "define.h"
#include "../Lazer.h"
#include "../Bullet.h"
#include "../GameTime.h"
#include "../GameMap.h"
#include "../GameGlobal.h"
#include <list>
class GameScene :public Scene
{
private:
	Bar* m_bar1;
	Bar* m_bar2;

	GameMap *m_gameMap;

	float m_currentTime = 0;
	float m_timeAddBlackArmy = 0;

	int m_lastMouseMoveX, m_lastMouseMoveY;

	bool Army_Lane[2][ARMY_NUM_LANE];


public:
	GameScene();
	~GameScene();
	virtual void Update(float deltime);
	virtual void Event(sf::Event event);
	virtual void Init();
	virtual void Render(sf::RenderWindow&);

	void CheckCollision();
};