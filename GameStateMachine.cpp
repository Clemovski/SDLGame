#include "GameStateMachine.h"
#include "InputHandler.h"


GameStateMachine::GameStateMachine() {}


GameStateMachine::~GameStateMachine() {}

void GameStateMachine::pushState(GameState *pState)
{
	m_gameStates.push_back(pState);
	m_gameStates.back()->onEnter();
}

void GameStateMachine::popState()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->setIsValid(false); // Mark the state as invalid
		/*
		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
		*/
	}
}

void GameStateMachine::changeState(GameState *pState)
{
	if (!m_gameStates.empty())
	{
		if (m_gameStates.back()->getStateID() == pState->getStateID())
		{
			return;	// do nothing
		}

		m_gameStates.back()->setIsValid(false); // Mark the state as invalid

		/* Passage supprimé pour réparer un bug. Voir http://www.reddit.com/r/learnprogramming/comments/1qiwes/c_following_sdl_game_development_book_state/
		
		if (m_gameStates.back()->onExit())
		{
			delete m_gameStates.back();
			m_gameStates.pop_back();
		}
		*/
	}

	// push back our new state
	m_gameStates.push_back(pState);

	//	Initialise it
	m_gameStates.back()->onEnter();
}

void GameStateMachine::update()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->update();
	}
}

void GameStateMachine::render()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->render();
	}
}

void GameStateMachine::dequeState()
{
	if (!m_gameStates.empty())
	{
		std::vector<GameState*>::iterator iterateur = m_gameStates.begin();
		int size = m_gameStates.size();

		for (int i = 0; i < size; i++)
		{
			// if the state is invalid we procees to dequeue the state
			if (!m_gameStates[i]->getIsValid() && m_gameStates[i]->onExit())
			{
				delete m_gameStates[i];
				m_gameStates.erase(iterateur);

				/*
				*Reset the input handler buttons state
				*this line is extremely important, fixes an issue with the state traveling
				*when a button is in the position of another button in another state.
				*This will prevent the accident of traveling 2 states with 1 click.
				*/
				TheInputHandler::Instance()->reset();
			}
			iterateur++;
		}
	}
}