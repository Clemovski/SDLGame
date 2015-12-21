#ifndef __GameStateMachine__
#define __GameStateMachine__

#include <vector>
#include "GameState.h"

class GameStateMachine
{
public:

	GameStateMachine();
	~GameStateMachine();

	void pushState(GameState* pState);		// add state without removing the previous
	void changeState(GameState* pState);	// remove previous state before adding another
	void popState();						// remove current state
	void dequeState();

	void update();
	void render();

private:

	std::vector<GameState*> m_gameStates;
};

#endif /* defined(_GameStateMachine_) */