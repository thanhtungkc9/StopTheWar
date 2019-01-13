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
sf::Sprite* RenderGameObject::GetSpriteAnim()
{
	return m_currentAnim->GetSprite();
}
void RenderGameObject::Render(sf::RenderWindow &rd)
{
	rd.draw(*m_sprite);
}

void RenderGameObject::Update(float deltime)
{
	m_currentAnim->Update(deltime);
	m_position += sf::Vector2f(m_velocityX*deltime, m_velocityY*deltime);
}

void RenderGameObject::SetDirection(int direction)
{
	m_currentDirection = direction;
}
void RenderGameObject::SetVelocity(float velX,float velY)
{
	m_velocityX = velX;
	m_velocityY = velY;
}
int RenderGameObject::GetStatus()
{
	return m_status;
}

int RenderGameObject::GetType()
{
	return m_type;
}
void RenderGameObject::Collision(RenderGameObject* collisionObject)
{

 }
void RenderGameObject::SetPosition(int posX, int posY)
{
	m_position.x = posX;
	m_position.y = posY;
}

 
 void RenderGameObject::SetPosition(sf::Vector2f position)
 {
	 m_position = position;
 }
 sf::Vector2f RenderGameObject::GetPosition()
 {
	return m_position ;
 }