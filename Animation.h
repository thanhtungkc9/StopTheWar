#pragma once
#include "SFML/Graphics.hpp"
#include "GameControllers/ResourcesManager.h"
class Animation
{
private:
	sf::Texture *m_textureAnim;
	sf::Sprite *m_spriteAnim;
	bool isLoop;
	bool isPause;
	int m_currentFrame=0;
	int m_totalFrame;
	int m_frameUpdate;
	int m_currentFrameCount = 0;

	float m_timePerFrame;
	float m_currentTime;

	eID m_eID;
	std::string m_nameAnimation;
public:
	Animation();
	Animation(eID texture_eID, int totalFrame, std::string nameAnimation, float timePerFrame);
	~Animation();
	sf::Sprite* GetSprite();
	int GetCurrentFrameIndex();
	int GetTotalFrame();
	void Update(float deltime);
	void Render(sf::RenderWindow &rd,sf::Vector2f = sf::Vector2f(0,0));
	std::string GetNameAnimation();
	eID GeteID();
};

