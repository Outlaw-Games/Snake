#pragma once
#include <string>
#include <Engine/OGLGame.h>
#include <..\\Projects\Snake\Object.h>

namespace ASGE {
	class Renderer;
	class Sprite;

}


class Player :
	public Object
{
public:

	Player() = default;
	~Player() = default;

bool loadAvatar(ASGE::Renderer* renderer) override;
void setPosX(int x) override;
void setPosY(int y) override;
	//ASGE::Sprite* getPlayer();
	
//	int getPlayerPosx() const;
	//int getPlayerPosy() const;
//	int Tail = 3;
//	void setPosX(int x);
//	void setPosY(int y);
	//void lastXY();

	//int LPosX() const;
	//int LPosY() const;


private:
	/*ASGE::Sprite* player = nullptr;
	int PlayerPosx;
	int PlayerPosy;
	int PlayerLastPosition;
	int lastPosX;
	int lastPosY;*/
};
