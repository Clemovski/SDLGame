#include "PlayState.h"

#include <iostream>
#include "Game.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "SDLGameObject.h"
#include "GameOverState.h"

const std::string PlayState::s_playID = "PLAY";

PlayState::PlayState() {}


PlayState::~PlayState() {}

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());
	}


	int size = (int)m_gameObjects.size();
	for (int i = 0; i < size; i++)
	{
		m_gameObjects[i]->update();
	}

	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[0])
		, dynamic_cast<SDLGameObject*>(m_gameObjects[1]) ))
	{
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
	}


	//Check and dequeue the state if it's invalid
	TheGame::Instance()->getStateMachine()->dequeState();
}

void PlayState::render()
{
	int size = (int)m_gameObjects.size();
	for (int i = 0; i < size; i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/helicopter.png", "helicopter", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/helicopter2.png", "helicopter2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	
	GameObject* player = new Player(new LoaderParams(500, 100, 128, 55, "helicopter"));
	GameObject* enemy = new Enemy(new LoaderParams(100, 100, 128, 55, "helicopter2"));

	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);

	std::cout << "Entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	int size = (int)m_gameObjects.size();
	for (int i = 0; i < size; i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");

	std::cout << "Exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	// Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if ( bottomA <= topB ){ return false; }
	if ( topA >= bottomB ){ return false; }
	if ( rightA <= leftB ){ return false; }
	if ( leftA >= rightB ){ return false; }

	return true;
}