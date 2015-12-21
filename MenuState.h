#ifndef __MenuState__
#define __MenuState__

#include <vector>
#include "GameState.h"
#include "GameObject.h"

class MenuState : public GameState
{
public:
	MenuState();
	~MenuState();

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_menuID; }

private:

	static const std::string s_menuID;

	std::vector<GameObject*> m_gameObjects;

	// callback functions for menu items
	static void s_menuToPlay();
	static void s_exitFromMenu();
};

#endif /* defined(_MenuState_) */