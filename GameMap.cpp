#include "pch.h"
#include "GameMap.h"


GameMap::GameMap()
{
}


GameMap::~GameMap()
{
}

void GameMap::AddArmy(RenderGameObject * army)
{
	m_listArmy.push_back(army);
}

void GameMap::AddArmyBullet(Bullet * armyBullet)
{
	m_listArmyBullet.push_back(armyBullet);
}

void GameMap::Init()
{

}

void GameMap::Render(sf::RenderWindow &rd)
{
	#pragma region Render Army
		for (std::list<RenderGameObject*>::iterator it = m_listArmy.begin(); it != m_listArmy.end(); it++)
		{
			(*it)->Render(rd);
		}
	#pragma endregion

	#pragma region Render Bullet
			for (std::list<Bullet*>::iterator it = m_listArmyBullet.begin(); it != m_listArmyBullet.end(); it++)
			{
				(*it)->Render(rd);
			}
	#pragma endregion
}

void GameMap::Update(float deltime)
{

	#pragma region Update Army
		for (std::list<RenderGameObject*>::iterator it = m_listArmy.begin(); it != m_listArmy.end(); )
		{
			if ((*it)->GetStatus() != RenderGameObject::Status::DEAD)
				(*it)->Update(deltime);
			else
			{
				RenderGameObject* tmp = *it;
				it++;
				m_listArmy.remove(tmp);
				delete tmp;
				continue;
			}

			if ((*it)->GetAnimation()->GeteID() == eID::BLACKARMY_SHOTGUN_SHOOT
				&& (*it)->GetAnimation()->GetCurrentFrameIndex() == (*it)->GetAnimation()->GetTotalFrame() - 2
				&& (*it)->GetStatus()!=RenderGameObject::Status::DESTROYING)
			{
				Bullet *bullet = new Bullet();
				bullet->Init();
				if ((*it)->GetDirection()==RenderGameObject::Direction::UP)
				bullet->SetPosition((*it)->GetAnimation()->GetSprite()->getGlobalBounds().left + (*it)->GetAnimation()->GetSprite()->getGlobalBounds().width *0.75,
					(*it)->GetAnimation()->GetSprite()->getGlobalBounds().top);
				else
					bullet->SetPosition((*it)->GetAnimation()->GetSprite()->getGlobalBounds().left + (*it)->GetAnimation()->GetSprite()->getGlobalBounds().width *0.25,
					(*it)->GetAnimation()->GetSprite()->getGlobalBounds().top + (*it)->GetAnimation()->GetSprite()->getGlobalBounds().height);
				bullet->SetDirection((*it)->GetDirection());
				m_listArmyBullet.push_back(bullet);
				(*it)->SetStatus(RenderGameObject::Status::DESTROYING);
			}
			
			it++;
		}
	#pragma endregion

	#pragma region Update Bullet
		for (std::list<Bullet*>::iterator it = m_listArmyBullet.begin(); it != m_listArmyBullet.end(); )
		{
			if ((*it)->GetStatus() != RenderGameObject::Status::DEAD)
				(*it)->Update(deltime);
			else
			{
				Bullet* tmp = *it;
				it++;
				m_listArmyBullet.remove(tmp);
				delete tmp;
				continue;
			}
			it++;
		}
	#pragma endregion

}


std::list<RenderGameObject*> GameMap::GetListArmy()
{
	return m_listArmy;
}
std::list<Bullet*> GameMap::GetListArmyBullet()
{
	return m_listArmyBullet;
}