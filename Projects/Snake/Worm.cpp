#include "Worm.h"
#include <Engine/Renderer.h>
#include <Engine/OglGame.h>



bool Worm::loadAvatar(ASGE::Renderer * renderer)
{
	avatar = renderer->createRawSprite();
	if (!avatar->loadTexture("..\\..\\Resources\\Textures\\Worm.png"))
		{
			return false;
		}

}

void Worm::setPosX(int x)
{
	posX = x;
}

void Worm::setPosY(int y)
{
	posY = y;
}

//ASGE::Sprite * Worm::getWorm()
//{
//	return worm_sprite;
//}
//
//int Worm::getPosX()
//{
//	return wormposx;
//}
//
//int Worm::getPosY()
//{
//	return wormposy;
//}
//
//void Worm::setPosX(int x)
//{
//	wormposx = x;
//}
//
//void Worm::setPosY(int y)
//{
//	wormposy = y;
//}
