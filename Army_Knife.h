#pragma once
#include "Objects/RenderGameObject.h"
#include "Animation.h"
#include "Objects/RenderGameObject.h"
class Army_Knife:public RenderGameObject
{
protected:
	Animation *m_movingAnim;
	Animation *m_movingFeetAnim;
	Animation *m_attackingAnim;

	Animation *m_Explosion;

	int m_HP;
public:
	Army_Knife();
	~Army_Knife();

	void ChangeDirection();

	virtual sf::Sprite* GetSprite();
	virtual sf::Sprite* GetSpriteAnim();

	virtual void Init();


	virtual void Render(sf::RenderWindow &);
	virtual void Update(float deltime);
	virtual void Collision(RenderGameObject* collisionObject);

	void Scale();
};

