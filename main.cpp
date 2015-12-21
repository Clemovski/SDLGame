#include "Game.h"
#include <stdio.h>	// Pour afficher les logs dans la console
#include <Windows.h> // Pour afficher la console

const int FPS = 60;	// Nombre de Frames Par Seconde
const float DELAY_TIME = 1000.0f / FPS;	// Temps entre chaque boucle

int main(int argc, char* args[])
{
	// Code de la console
	AllocConsole();
	FILE* sttream = 0;
	freopen_s(&sttream, "CON", "w", stdout);
	// A dégager à la fin du projet

	Uint32 frameStart, frameTime;

	std::cout << "Game init attempt ...\n";
	if (TheGame::Instance()->init("Chapter 1", 100, 100, 640, 480, false))
	{
		std::cout << "Game init success !\n";
		while (TheGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();

			TheGame::Instance()->handleEvents();
			TheGame::Instance()->update();
			TheGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			if (frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		std::cout << "Game init failure - " << SDL_GetError() << "\n";
		return -1;
	}

	std::cout << "Game closing ...\n";
	TheGame::Instance()->clean();

	return 0;
}