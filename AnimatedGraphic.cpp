#include "AnimatedGraphic.h"


AnimatedGraphic::AnimatedGraphic(const LoaderParams* params, int animSpeed) : SDLGameObject(params), m_animSpeed(animSpeed)
{
}


AnimatedGraphic::~AnimatedGraphic()
{
}

void AnimatedGraphic::update()
{
	m_numFrames = 2;	//A supprimer
	m_currentFrame = int(((SDL_GetTicks() / (1000 / m_animSpeed)) % m_numFrames));
}


void AnimatedGraphic::draw()
{
	SDLGameObject::draw();
}


void AnimatedGraphic::clean()
{
	SDLGameObject::clean();
}