#pragma once
#include "SFML/Audio.hpp"
class SoundManager
{
public:
	static SoundManager* getInstance();
	static void release();
	//void LoadSoundResources();

	void PlaySound();

	~SoundManager(void);


private:
	SoundManager(void);
	sf::SoundBuffer m_soundBuffer;
	sf::Sound m_sound;
	static SoundManager* _instance;
	

};