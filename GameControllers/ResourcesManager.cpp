#include "ResourcesManager.h"

ResourcesManager* ResourcesManager::_instance = nullptr;
ResourcesManager::ResourcesManager(void)
{
	// do nothing.
}

ResourcesManager::~ResourcesManager(void)
{
	for (auto spr = m_listTexture.begin(); spr != m_listTexture.end(); ++spr)
	{
		delete spr->second;			// delete sprite
	}
	if (m_listTexture.empty() == false)
		m_listTexture.clear();		// remove all from MAP
}


void ResourcesManager::LoadResource()
{

	sf::Texture* texture = NULL;


	texture = new sf::Texture();
	texture->loadFromFile("Resources/Textures/Bar/Bar.png");
	this->m_listTexture.insert(std::pair<eID, sf::Texture*>(eID::BAR, texture));
	this->LoadTextureInfo(eID::BAR, "Resources//Textures//Bar//Bar.txt");

	texture = new sf::Texture();
	texture->loadFromFile("Resources/Textures/Monsters/YellowRedMonster.png");
	this->m_listTexture.insert(std::pair<eID, sf::Texture*>(eID::REDMONSTER, texture));
	this->LoadTextureInfo(eID::REDMONSTER, "Resources//Textures//Monsters//YellowRedMonster.txt");

/*
	sp = new Sprite("Resources/AnimationInfo/guard_number2.png");
	this->_listSprite.insert(pair<eID, Sprite*>(eID::GUARD_NUMBER2, sp));
	this->loadSpriteInfo(eID::GUARD_NUMBER2, "Resources//AnimationInfo//guard_number2.txt");

	sp = new Sprite("Resources/AnimationInfo/Items.png", RECT(), NULL, NULL, D3DCOLOR_XRGB(255, 0, 255));
	this->_listSprite.insert(pair<eID, Sprite*>(eID::ITEMS, sp));
	this->loadSpriteInfo(eID::ITEMS, "Resources//AnimationInfo//Items.txt");
	*/
}




sf::Texture* ResourcesManager::GetTexture(eID id)
{
	sf::Texture *it = this->m_listTexture.find(id)->second;
	return new sf::Texture(*it);			
}

sf::IntRect ResourcesManager::GetSourceRect(eID id, std::string name)
{

	return m_sourceRectList[id][name];
}

void ResourcesManager::LoadTextureInfo(eID id, const char* fileInfoPath)
{
	FILE* file;
	file = fopen(fileInfoPath, "r");

	if (file)
	{
		while (!feof(file))
		{
			sf::IntRect rect =sf::IntRect();
			
			char name[100];
			fgets(name, 100, file);
			
			fscanf(file, "%s %d %d %d %d", &name, &rect.left, &rect.top, &rect.width, &rect.height);	
			m_sourceRectList[id][std::string(name)] = rect;
		}
	}

	fclose(file);
}


void ResourcesManager::releaseTexture(eID id)
{
	sf::Texture *spr = this->m_listTexture.find(id)->second;				// release image
	delete spr;
	this->m_listTexture.erase(id);		// erase funciotn only remove the pointer from MAP, dont delete it.
}
ResourcesManager* ResourcesManager::getInstance()
{
	if (_instance == nullptr)
		_instance = new ResourcesManager();
	return _instance;
}

void ResourcesManager::release()
{
	delete _instance;			// _instance is static attribute, only static function can delete it.
	_instance = nullptr;
}