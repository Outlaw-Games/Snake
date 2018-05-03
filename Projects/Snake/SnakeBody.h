#pragma once
#include <string>
#include <Engine/OGLGame.h>
#include <..\\Projects\Snake\Object.h>

namespace ASGE {
	class Renderer;
	class Sprite;

}


class SnakeBody: 
	public Object
{
public:

	SnakeBody() = default;
	~SnakeBody() = default;

	bool loadAvatar(ASGE::Renderer* renderer);
	void setPosX(int x) override;
	void setPosY(int y) override;
	/*ASGE::Sprite* getSnakeBody();

	int getPosX();
	int getPosY();
	void setPosX(int x);
	void setPosY(int y);
	void lastXY();

	int LPosX() const;
	int LPosY() const;*/

	//void yes(ASGE::Renderer * renderer);



private:
	/*ASGE::Sprite* snakebody_sprite = nullptr;
	int snakebodyposx;
	int snakebodyposy;

	int SnakeBodyLastPosition;
	int lastPosX;
	int lastPosY;*/
};
