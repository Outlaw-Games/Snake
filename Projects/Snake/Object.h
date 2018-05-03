#pragma once
#include <string>
#include <Engine/OGLGame.h>
#include<Engine/Sprite.h>

namespace ASGE {
	class Renderer;
	class Sprite;

}


class Object
{
public:

	Object() = default;
	~Object()= default;

	virtual bool loadAvatar(ASGE::Renderer* renderer) = 0;
	/*virtual void setDefault() = 0;*/
	virtual void setPosX(int x) = 0;
	virtual	void setPosY(int y) = 0;

	virtual ASGE::Sprite * getObject() const { return avatar; }
	virtual void Object::getRenderer(ASGE::Renderer* renderer);


	virtual int getPosx() const {return posX;}
	virtual int getPosy() const { return posY; }
	virtual void lastXY(){	lastPosY = posY, lastPosX = posX;}

	virtual int LPosX() const {return lastPosX;}
	virtual int LPosY() const { return lastPosY; }
	virtual void setLPosX(int x);
	virtual void setLPosY(int y);

	ASGE::Sprite* avatar = nullptr;

protected:	
	int posX;
	int posY;
	int LastPosition;
	int lastPosX;
	int lastPosY;
};
