#include "Animation.h"



Animation::Animation()
{
}


Animation::~Animation()
{
}

Animation::Animation(eID texture_eID, int totalFrame, std::string nameAnimation, float timePerFrame)
{
	m_eID = texture_eID;
	m_nameAnimation = nameAnimation;

	m_textureAnim = ResourcesManager::getInstance()->GetTexture(texture_eID);
	m_spriteAnim = new sf::Sprite();
	m_spriteAnim->setTexture(*m_textureAnim);

	m_totalFrame = totalFrame;
	m_timePerFrame = timePerFrame;

}
sf::Sprite* Animation::GetSprite()
{
	return m_spriteAnim;
}
int Animation::GetCurrentFrameIndex()
{
	return m_currentFrame;
}
int Animation::GetTotalFrame()
{
	return m_totalFrame;
}
void Animation::Update(float deltime)
{
	if (m_totalFrame == 1) return;
	if (m_currentTime >= m_timePerFrame)
	{
		m_spriteAnim->setTextureRect(ResourcesManager::getInstance()->GetSourceRect(m_eID, m_nameAnimation + std::to_string(m_currentFrame)));
		sf::IntRect rect;
		rect = ResourcesManager::getInstance()->GetSourceRect(m_eID, m_nameAnimation + std::to_string(m_currentFrame));
		Point origin = ResourcesManager::getInstance()->GetOriginPoint(m_eID, m_nameAnimation + std::to_string(m_currentFrame));
		m_spriteAnim->setOrigin(sf::Vector2f(origin.x,origin.y));

		m_currentFrame += 1;

		if (m_currentFrame >= m_totalFrame)
		{
			m_currentFrame = 0;
		}

		m_currentTime = 0;
	}
	else
	{
		m_currentTime += deltime;
	}
}
void Animation::Render(sf::RenderWindow &rd)
{
	rd.draw(*m_spriteAnim);
}