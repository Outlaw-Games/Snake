#include "Cherry.h"
#include <Engine/Renderer.h>
#include <Engine/OglGame.h>



bool Cherry::loadAvatar(ASGE::Renderer * renderer)
{

	avatar= renderer->createRawSprite();
	if (!avatar->loadTexture("..\\..\\Resources\\Textures\\Cherry.png"))
	{
		return false;
	}
}

void Cherry::setPosX(int x)
{
	posX = x;
}

void Cherry::setPosY(int y)
{
	posY = y;
}

//void Cherry::setDefault()
//{
//	posX = 100;
//	posY = 100;
//}



/*ASGE::Sprite * Cherry::getCherry()
{
	return cherry_sprite;
}

int Cherry::getPosX()
{
	return cherryposx;
}

int Cherry::getPosY()
{
	return cherryposy;
}

void Cherry::setPosX(int x)
{
	cherryposx = x;
}

void Cherry::setPosY(int y)
{
	cherryposy = y;
}*/
