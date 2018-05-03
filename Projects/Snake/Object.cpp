#include "Object.h"
#include <Engine/Renderer.h>
#include <Engine/OglGame.h>

void Object::getRenderer(ASGE::Renderer * renderer)
{
	avatar->position[0] = posX;
	avatar->position[1] = posY;
	renderer->renderSprite(*avatar);
}

void Object::setLPosX(int x)
{
	lastPosX = x;
}

void Object::setLPosY(int y)
{
	lastPosY = y;
}

