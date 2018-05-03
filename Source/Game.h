#pragma once
#include <string>
#include <Engine/OGLGame.h>
#include <..\\Projects\Snake\Player.h>
#include <..\\Projects\Snake\Hole.h>
#include "..\Projects\Snake\Cherry.h"
#include<..\\Projects\Snake\Worm.h>
#include<..\\Projects\Snake\Tree.h>
#include<..\\Projects\Snake\SnakeBody.h>
#include<..\\Projects\Snake\Object.h>
struct GameFont;

/**
*  SnakeGame. An OpenGL Game based on ASGE.
*/

class SnakeGame:
	public ASGE::OGLGame
{
public:
	SnakeGame();
	~SnakeGame();
	virtual bool init() override;
	//ASGE::Sprite* sprite = nullptr;    //tree
	//ASGE::Sprite*  sprite2 = nullptr; //player
	//ASGE::Sprite* sprite3 = nullptr; //cherry
	//ASGE::Sprite* sprite4 = nullptr; //hole
	//ASGE::Sprite* sprite5 = nullptr; // worm
	//ASGE::Sprite* sprite6 = nullptr; //snakebody
	int tail;
	
	
	


private:


	void processGameActions();
	void processGameMovement();
	void input(ASGE::SharedEventData data) const;
	bool shouldExit() const;
	int Boardwidth = 1550;
	int Boardheight = 950;
	double my_game_time;
	double last_update;
	

	bool Collision(int ax, int ay, int bx, int by);
	bool HoleCollision(int dx, int dy, int cx,int cy);
	bool WormCollision(int fx, int fy, int ex, int ey);
	bool TreeCollision(int ix, int iy, int jx, int jy);
//	bool WallCollision(int hx, int hy, int gx, int gy);

	Cherry* my_cherry = nullptr;
	Player* player = nullptr;
	Hole* hole = nullptr;
	Worm* my_worm = nullptr;
	Tree* my_tree = nullptr;
	SnakeBody* my_snakeArray[10];
	Tree* my_treeArray[10];
	SnakeBody* my_snake;
	// Inherited via OGLGame
	virtual void update(const ASGE::GameTime & time) override;
	virtual void render(const ASGE::GameTime &) override;

	int  callback_id = -1;             /**< Input Callback ID. The callback ID assigned by the game engine. */
	bool exit = false;     
	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;
	bool pause = false;
	bool start = false;
	bool GameOver = false;
	bool UnderGround = false;
	int score = 0;
};

