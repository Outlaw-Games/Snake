#pragma once
#include <string>
#include <Engine/OGLGame.h>
#include <..\\Projects\Snake\Object.h>

namespace ASGE {
	class Renderer;
	class Sprite;

}


class Hole :
	public Object
{
public:

	Hole() = default;
	~Hole() = default;

	bool loadAvatar(ASGE::Renderer* renderer);
	void setPosX(int x) override;
	void setPosY(int y) override;

//	ASGE::Sprite* getHole();

//	int getPosX();
//	int getPosY();
//	void setPosX(int x);
//	void setPosY(int y);


private:
//	ASGE::Sprite* hole_sprite = nullptr;
//	int holeposx;
	//int holeposy;
};