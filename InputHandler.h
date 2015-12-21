#ifndef __InputHandler__
#define __InputHandler__

#include "SDL.h"
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:

	// Singleton
	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}

		return s_pInstance;
	}

	void reset();

	// Update and Clean the InputHandler
	void update();
	void clean();

	// Initialise sticks
	void initialiseJoysticks();
	bool joysticksInitialised()	const { return m_bJoysticksInitialised; }

	// Stick events
	int xvalue(int joy, int stick) const;	// stick : 1 = gauche, 2 = droit
	int yvalue(int joy, int stick) const;
	bool getButtonState(int joy, int buttonNumber) const { return m_buttonStates[joy][buttonNumber]; }

	// Souris events
	bool getMouseButtonState(int buttonNumber) const { return m_mouseButtonStates[buttonNumber]; }
	Vector2D* getMousePosition() const { return m_mousePosition; }

	// Clavier events
	bool isKeyDown(SDL_Scancode key) const;

private:

	InputHandler();
	~InputHandler();

	static InputHandler* s_pInstance;

	// Joystick members
	bool m_bJoysticksInitialised;
	const int m_joystickDeadZone = 10000;
	std::vector<SDL_Joystick*> m_joysticks;
	std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;	// Un Vector2D par stick (2) pour chaque controler
	std::vector<std::vector<bool>> m_buttonStates;

	// Handle Joystick events
	void onJoystickAxisMove(SDL_Event& event);
	void onJoystickButtonDown(SDL_Event& event);
	void onJoystickButtonUp(SDL_Event& event);

	// Souris members
	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;

	// Handle Souris events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	// Clavier members
	const Uint8* m_keystates;

	// Handle Clavier events
	void onKeyDown();
	void onKeyUp();
};

typedef InputHandler TheInputHandler;

#endif; /* defined(_InputHandler_) */