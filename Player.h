#ifndef __Player__
#define __Player__

#include "SDLGameObject.h"

class Player : public SDLGameObject
{
public:

	Player(const LoaderParams* pParams);
	~Player() {};

	virtual void draw();
	virtual void update();
	virtual void clean();
	void handleInput();
};

#endif; /* defined(_Player_) */