#pragma once
class GameGlobal
{
public:
	static GameGlobal* getInstance();
	static void release();

	 int GetScore();
	 void SetScore(int Score);
	 int GetHealth();
	 void SetHealth(int health);

	GameGlobal(void);
	~GameGlobal(void);
private:
	static GameGlobal* _instance;

	int m_score=0;
	int m_health = 3;
};
