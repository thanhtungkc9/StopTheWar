#pragma once
#include "GameObject.h"
#include <iostream>
#include <string>
class RenderGameObject :public GameObject
{
protected:
	sf::Texture *m_texture;
	sf::Sprite *m_sprite;

	float m_speed;

	int m_currentDirection;

public:
	enum Direction
	{
		LEFT = -1,
		RIGHT = 1,
		UP = -2,
		DOWN = 2
	};

	RenderGameObject();
	~RenderGameObject();

	virtual sf::Sprite* GetSprite();
	virtual void Init();
	virtual void Render(sf::RenderWindow &) ;
	virtual void Update(float deltime);

	virtual void Init(std::string filePath);
};