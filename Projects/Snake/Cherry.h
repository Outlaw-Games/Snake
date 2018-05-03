#pragma once
#include <string>
#include <Engine/OGLGame.h>
#include <..\\Projects\Snake\Object.h>

namespace ASGE {
	class Renderer;
	class Sprite;

}


class Cherry :
	public Object
{
public:

	Cherry() = default;
	~Cherry() = default;

	bool loadAvatar(ASGE::Renderer* renderer);
	void setPosX(int x) override;
	void setPosY(int y) override;
	//void setDefault() override;
	/*ASGE::Sprite* getCherry();

	int getPosX();
	int getPosY();
	void setPosX(int x);
	void setPosY(int y);
*/

private:
	/*ASGE::Sprite* cherry_sprite = nullptr;
	int cherryposx;
	int cherryposy;*/
};
