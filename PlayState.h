#pragma once
#include "GameState.h"
#include "GameObject.h"
#include "SDLGameObject.h"
#include <vector>

class PlayState : public GameState
{
public:
	PlayState();
	~PlayState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_playID; }

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

private:
	
	static const std::string s_playID;

	std::vector<GameObject*> m_gameObjects;
};

