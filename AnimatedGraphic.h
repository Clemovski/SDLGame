#pragma once
#include "SDLGameObject.h"
#ifndef __AnimatedGraphic__
#define __AnimatedGraphic__

class AnimatedGraphic :
	public SDLGameObject
{
public:
	AnimatedGraphic(const LoaderParams* params, int animSpeed);
	~AnimatedGraphic();

	virtual void update();
	virtual void draw();
	virtual void clean();

private:
	int m_animSpeed;
};

#endif /* defined(_AnimatedGraphic_) */