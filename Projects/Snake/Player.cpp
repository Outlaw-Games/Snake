#include "Player.h"
#include <Engine/Renderer.h>
#include <Engine/OglGame.h>



bool Player::loadAvatar(ASGE::Renderer * renderer)
{
	avatar = renderer->createRawSprite();
	if (!avatar->loadTexture("..\\..\\Resources\\Textures\\Player.png"))
	{
		return false;
	}
}
void Player::setPosX(int x)
{
	posX += x;
}
void Player::setPosY(int y)
{
	posY += y;
}
//
//void Player::lastXY()
//{
//	lastPosY = PlayerPosy;
//	lastPosX = PlayerPosx;
//}
//
//int Player::LPosX() const
//{
//	return lastPosX;
//}
//
//int Player::LPosY() const
//{
//	return lastPosY;
//}
//
////ASGE::Sprite * Player::getPlayer()
////{
////	return player;
////}
//
//int Player::getPlayerPosx() const
//{
//	return PlayerPosx;
//}
//
//int Player::getPlayerPosy() const
//{
//	return PlayerPosy;
//}
//
//void Player::setPosX(int x)
//{
//	PlayerPosx = x;
//}
//void Player::setPosY(int y)
//{
//	PlayerPosy = y;
//}