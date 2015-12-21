#ifndef __PauseState__
#define __PauseState__

#include <vector>
#include "GameState.h"
#include "GameObject.h"

class PauseState :
	public GameState
{
public:
	PauseState() {}
	~PauseState() {}

	virtual void update();
	virtual void render();

	virtual bool onEnter();
	virtual bool onExit();

	virtual std::string getStateID() const { return s_pauseID; }

private:

	static void s_pauseToMain();
	static void s_resumePlay();

	static const std::string s_pauseID;

	std::vector<GameObject*> m_gameObjects;
};

#endif /* defined(_PauseState_) */