#include "RenderGameObject.h"

RenderGameObject::RenderGameObject()
{

}

RenderGameObject::~RenderGameObject()
{

}

void RenderGameObject::Init()
{

}

void RenderGameObject::Init(std::string filePath)
{
	m_texture = new sf::Texture();
	m_texture->loadFromFile(filePath);
	
	m_sprite = new sf::Sprite();
	m_sprite->setTexture(*m_texture);
}

sf::Sprite* RenderGameObject::GetSprite()
{
	return m_sprite;
}
void RenderGameObject::Render(sf::RenderWindow &rd)
{
	rd.draw(*m_sprite);
}

void RenderGameObject::Update(float deltime)
{
	
}