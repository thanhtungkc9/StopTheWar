#pragma once
#include "Objects\RenderGameObject.h"
#include <list>
#include "Bullet.h"
class GameMap
{
private:
	std::list<RenderGameObject*> m_listArmy;
	std::list<Bullet*> m_listArmyBullet;
public:	

	GameMap();
	~GameMap();

	std::list<RenderGameObject*> GetListArmy();
	std::list<Bullet*> GetListArmyBullet();
	void AddArmy(RenderGameObject * army);
	void AddArmyBullet(Bullet * armyBullet);
	virtual void Init() ;
	virtual void Render(sf::RenderWindow &) ;
	virtual void Update(float) ;
};

