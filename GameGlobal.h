#pragma once
class GameGlobal
{
public:
	static GameGlobal* getInstance();
	static void release();

	GameGlobal(void);
	~GameGlobal(void);
private:
	static GameGlobal* _instance;
};
