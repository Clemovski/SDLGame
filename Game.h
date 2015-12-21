#ifndef __Game__
#define __Game__

#include <SDL.h>
#include <iostream> // Pour les std::cout de la console
#include <vector>
#include "GameObject.h"
#include "TextureManager.h"
#include "GameStateMachine.h"

class Game
{
public:

	static Game* Instance() {
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
		}
		return s_pInstance;
	}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();

	void update();
	void handleEvents();
	void clean();

	bool running() { return m_bRunning; }

	SDL_Renderer* getRenderer() const { return m_pRenderer; }
	GameStateMachine* getStateMachine() { return m_pGameStateMachine; }

private:

	static Game* s_pInstance;

	Game(){}
	~Game();

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	bool m_bRunning;

	//std::vector<GameObject*> m_gameObjects;

	GameStateMachine* m_pGameStateMachine;

};

typedef Game TheGame;

#endif /* defined(_Game_) */