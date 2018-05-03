#include "Hole.h"
#include <Engine/Renderer.h>
#include <Engine/OglGame.h>

bool Hole::loadAvatar(ASGE::Renderer * renderer)
{

	avatar = renderer->createRawSprite();
	if (!avatar->loadTexture("..\\..\\Resources\\Textures\\Hole.png"))
	{
		return false;
	}

}
void Hole::setPosX(int x)
{
	posX = x;
}
void Hole::setPosY(int y)
{
	posY = y;
}
//ASGE::Sprite * Hole::getHole()
//{
//	return hole_sprite;
//}
//
//int Hole::getPosX()
//{
//	return holeposx;
//}
//
//int Hole::getPosY()
//{
//	return holeposy;
//}
//
//void Hole::setPosX(int x)
//{
//	holeposx = x;
//}
//
//void Hole::setPosY(int y)
//{
//	holeposy = y;
//}
