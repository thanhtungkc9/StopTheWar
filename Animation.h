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
	int m_currentFrame;
	int m_totalFrame;
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
	void Render(sf::RenderWindow &rd);
};

