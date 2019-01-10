#pragma once
#include "SFML\Graphics.hpp"

class Scene
{
protected:
	sf::Sprite *m_spriteBackGround;
	sf::Text *m_textureBackGround;

	sf::Font *m_textFont;
	sf::Text *m_score;
public:
	virtual void Update(float deltime);
	virtual void Init();
	virtual void Render(sf::RenderWindow&);

	virtual void Event(sf::Event event);

	~Scene();

protected:
	Scene();

private:

};