#include "Game.h"
#include "LoaderParams.h"
#include "Player.h"
#include "Enemy.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		
		if (m_pWindow != 0) // window init success
		{
			std::cout << "Window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "Renderer creation success\n";
				//RED GREEN BLUE
				SDL_SetRenderDrawColor(m_pRenderer, 74, 112, 139, 255);
			}
			else
			{
				std::cout << "Renderer init fail\n";
			}
		}
		else
		{
			std::cout << "Window init fail\n";
			return false; // Window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}

	TheInputHandler::Instance()->initialiseJoysticks();

	//Final State Machine
	m_pGameStateMachine = new GameStateMachine();
	m_pGameStateMachine->changeState(new MenuState());

	std::cout << "Init Success\n";
	m_bRunning = true; // Everything inited successfully, start the main loop

	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear the renderer to draw the color

	m_pGameStateMachine->render();

	SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::clean()
{
	std::cout << "Cleaning game\n";
	TheInputHandler::Instance()->clean();
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	TheInputHandler::Instance()->update();

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
	{
		m_pGameStateMachine->changeState(new PlayState());
	}
}

void Game::update()
{
	m_pGameStateMachine->update();
}