#pragma once
#include "RenderGameObject.h"
#include "../GameControllers/ResourcesManager.h"
#include <string>
#include "Bar.h"
class Monster:public RenderGameObject
{
protected:
	float m_timePerFrame;
	int m_currentFrame;
	float m_currentTime;
	int m_numFrames; 
	

	Bar *m_bar;
	int HP;
public:
	Monster()	{};
	virtual void CollisionWithScreenBound()=0;
	virtual void Init()=0;
	virtual void Render(sf::RenderWindow &)=0;
	virtual void Update(float deltime)=0;

	virtual sf::Sprite* GetSprite()=0;
	virtual void Init(std::string filePath)=0;
	virtual void SetBar(Bar *bar)=0;
	virtual void SetTwoBar(Bar *bar1, Bar *bar2)=0;
};