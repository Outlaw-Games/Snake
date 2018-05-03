#include "SnakeBody.h"
#include <Engine/Renderer.h>
#include <Engine/OglGame.h>




bool SnakeBody::loadAvatar(ASGE::Renderer * renderer)
{
	avatar = renderer->createRawSprite();
	//avatar->loadTexture("..\\..\\Resources\\Textures\\Body.png");
	if (!avatar->loadTexture("..\\..\\Resources\\Textures\\Body.png"))
	{
		return false;
	}
}
void SnakeBody::setPosX(int x)
{
	posX = x;
}
void SnakeBody::setPosY(int y)
{
	posY = y;
}
//ASGE::Sprite * SnakeBody::getSnakeBody()
//{
//	return snakebody_sprite;
//}
//
//int SnakeBody::getPosX()
//{
//	return snakebodyposx;
//}
//
//int SnakeBody::getPosY()
//{
//	return snakebodyposy;
//}
//
//void SnakeBody::setPosX(int x)
//{
//	snakebodyposx = x;
//}
//
//void SnakeBody::setPosY(int y)
//{
//	snakebodyposy = y;
//}
//
//void SnakeBody::lastXY()
//{
//	lastPosY = snakebodyposy;
//	lastPosX = snakebodyposx;
//}
//
//int SnakeBody::LPosX() const
//{
//	return lastPosX;
//}
//
//int SnakeBody::LPosY() const
//{
//	return lastPosY;
//}
//
////void SnakeBody::yes(ASGE::Renderer * renderer)
////{
//
//	
//	//renderer->renderSprite(*snakebody_sprite);
//	//snakebody_sprite->position[0] = x;
//	//snakebody_sprite->position[1] = y;
//
////}
//
///*
//	avatar->position[0] = pos_x;
//	avatar->position[1] = pos_y;
//	renderer->renderSprite(*avatar);
//*/
