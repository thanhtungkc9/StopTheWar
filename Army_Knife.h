#pragma once
#include "Objects/RenderGameObject.h"
#include "Animation.h"
class Army_Knife:RenderGameObject
{
protected:
	Animation *m_movingAnim;
	Animation *m_movingFeetAnim;
	Animation *m_attackingAnim;
	Animation *m_attackingFeetAnim;
public:
	Army_Knife();
	~Army_Knife();
};

