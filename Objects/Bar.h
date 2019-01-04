#pragma once
#include "RenderGameObject.h"

class Bar :public RenderGameObject
{
private:
	float m_timePerFrame;
	float m_currentTime;
	int m_numFrames;
	int m_currentFrame;

	void CollisionWithScreenBound();
public:
	Bar();
	Bar(int posX,int posY,int direction=RIGHT);
	~Bar();
	virtual void Init();
	virtual void Init(std::string);
	virtual sf::Sprite* GetSprite();
	virtual void Update(float);
	virtual void Render(sf::RenderWindow&);
};
