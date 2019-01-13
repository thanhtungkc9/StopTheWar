#include "GameGlobal.h"

GameGlobal* GameGlobal::_instance = nullptr;
GameGlobal::GameGlobal(void)
{
	// do nothing.
}
GameGlobal::~GameGlobal(void)
{

}

void GameGlobal::release()
{
	delete _instance;			// _instance is static attribute, only static function can delete it.
	_instance = nullptr;
}