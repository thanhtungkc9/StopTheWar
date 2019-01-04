#pragma once
#include "SFML\Graphics.hpp"

class Scene
{
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