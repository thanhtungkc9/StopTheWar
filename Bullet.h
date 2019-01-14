#pragma once
#include "Objects/RenderGameObject.h"
#include "Animation.h"
#include "Objects/RenderGameObject.h"
class Bullet :public RenderGameObject
{
protected:
	Animation *m_movingAnim;
	Animation *m_attackingAnim;

	Animation *m_Explosion;

	int m_HP;

public:
	Bullet();
	~Bullet();


	virtual void Init();


	virtual void Render(sf::RenderWindow &);
	virtual void Update(float deltime);
	virtual void Collision(RenderGameObject* collisionObject);

	void Scale();
};

