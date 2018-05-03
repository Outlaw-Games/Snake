#include "Tree.h"
#include <Engine/Renderer.h>
#include <Engine/OglGame.h>


bool Tree::loadAvatar(ASGE::Renderer * renderer)
{

	avatar = renderer->createRawSprite();
	if (!avatar->loadTexture("..\\..\\Resources\\Textures\\Tree.png"))
	{
		return false;
	}
}
void Tree::setPosX(int x)
{
	posX = x;
}
void Tree::setPosY(int y)
{
	posY = y;
}
//ASGE::Sprite * Tree::getTree()
//{
//	return tree_sprite;
//}

//int Tree::getPosX()
//{
//	return treeposx;
//}
//
//int Tree::getPosY()
//{
//	return treeposy;
//}
//
//void Tree::setPosX(int x)
//{
//	treeposx = x;
//}
//
//void Tree::setPosY(int y)
//{
//	treeposy = y;
//}