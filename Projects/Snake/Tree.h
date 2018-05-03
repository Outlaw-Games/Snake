#pragma once
#include <string>
#include <Engine/OGLGame.h>
#include <..\\Projects\Snake\Object.h>

namespace ASGE {
	class Renderer;
	class Sprite;

}


class Tree :
	public Object
{
public:

	Tree() = default;
	~Tree() = default;

	bool loadAvatar(ASGE::Renderer* renderer) override;
	
	void setPosX(int x) override;
	void setPosY(int y) override;
//	//ASGE::Sprite* getTree();
//
//	//int getPosX();
//	//int getPosY();
//	void setPosX(int x);
//	void setPosY(int y);
//
//
private:
//	ASGE::Sprite* tree_sprite = nullptr;
	//int treeposx;
//	int treeposy;
//
};