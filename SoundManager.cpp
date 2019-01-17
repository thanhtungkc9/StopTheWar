#include "SoundManager.h"


SoundManager* SoundManager::_instance = nullptr;
SoundManager::SoundManager(void)
{
}


SoundManager::~SoundManager(void)
{
}
SoundManager* SoundManager::getInstance()
{
	if (_instance == nullptr)
		_instance = new SoundManager();
	return _instance;
}

void SoundManager::release()
{
	delete _instance;			// _instance is static attribute, only static function can delete it.
	_instance = nullptr;
}
void SoundManager::PlaySound()
{
	m_soundBuffer.loadFromFile("Resources/Sounds/explosion.wav");
	m_sound.setBuffer(m_soundBuffer);
	m_sound.play();
}