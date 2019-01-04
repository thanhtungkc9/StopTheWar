#pragma once
#include "RenderGameObject.h"
#include "../GameControllers/ResourcesManager.h"
#include <string>
#include "Bar.h"
class Monster:RenderGameObject
{
protected:
	float m_timePerFrame;
	int m_currentFrame=1;
	float m_currentTime=0;
	int m_numFrames; 
	void CollisionWithScreenBound();
	

	Bar *m_bar;
	int HP = 1;
public:
	Monster(float posX, float posY, int direction=Direction::DOWN,std::string filePath="");
	virtual void Init();
	virtual void Render(sf::RenderWindow &);
	virtual void Update(float deltime);
	virtual sf::Sprite* GetSprite();
	virtual void Init(std::string filePath);
	void SetBar(Bar *bar);
};