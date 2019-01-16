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

	float m_difficult = 1.0f;

	int m_timeLeft = 90;
	int m_currentTimeLeft = 90;



	sf::Font *m_textFont;
	sf::Text *m_scoreText;
	sf::Text *m_healthText;
	sf::Text *m_currentTimeLeftText;

	bool m_isAddArmy = true; // add 1 enemy if bullet get through 2 walls
	float m_lasPosX;

public:
	GameScene();
	~GameScene();
	virtual void Update(float deltime);
	virtual void Event(sf::Event event);
	virtual void Init();
	virtual void Render(sf::RenderWindow&);

	void CheckCollision();
};