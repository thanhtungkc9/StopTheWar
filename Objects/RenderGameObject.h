#pragma once
#include "GameObject.h"
#include <iostream>
#include <string>
#include "../Animation.h"
#include "../GameGlobal.h"


class RenderGameObject :public GameObject
{
protected:
	sf::Texture *m_texture;
	sf::Sprite *m_sprite;
	Animation *m_currentAnim;

	sf::Vector2f m_position;

	float m_speed;
	float m_velocityX;
	float m_velocityY;

	int m_currentDirection;
	int m_status;
	int m_type;


public:
	enum Direction
	{
		LEFT = -1,
		RIGHT = 1,
		UP = -2,
		DOWN = 2
	};
	enum Status
	{
		ALIVE,
		DESTROYING,
		DEAD
	};
	enum Type
	{
		BLACKARMY,
		REDARMY,
		BARRIER,
		LAZER,
		BULLET
	};
	RenderGameObject();
	~RenderGameObject();

	virtual sf::Sprite* GetSprite();
	virtual sf::Sprite* GetSpriteAnim();
	virtual void Init();
	virtual void Init(std::string filePath);

	virtual void Render(sf::RenderWindow &) ;
	virtual void Update(float deltime);

	virtual void SetDirection(int direction);
	int GetDirection();

	void SetSpeed(float speed);
	void SetVelocity(float velX, float velY);

	int GetStatus();
	void SetStatus(int status);

	int GetType();
	Animation* GetAnimation();


	 void SetPosition(int posX, int posY);
	 void SetPosition(sf::Vector2f position);
	 sf::Vector2f GetPosition();
	virtual void Collision(RenderGameObject* collisionObject);

};