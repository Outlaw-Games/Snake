#pragma once
#include <string>
#include <Engine/OGLGame.h>
#include <..\\Projects\Snake\Object.h>

namespace ASGE {
	class Renderer;
	class Sprite;

}


class Worm :
	public Object
{
public:

	Worm() = default;
	~Worm() = default;

	bool loadAvatar(ASGE::Renderer* renderer);
	void setPosX(int x) override;
	void setPosY(int y) override;
	/*ASGE::Sprite* getWorm();

	int getPosX();
	int getPosY();
	void setPosX(int x);
	void setPosY(int y);*/


private:
	/*ASGE::Sprite* worm_sprite = nullptr;
	int wormposx;
	int wormposy;*/
};
