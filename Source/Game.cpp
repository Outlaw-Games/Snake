#include <Engine/Keys.h>
#include <Engine/Input.h>
#include <Engine/InputEvents.h>
#include <Engine/Sprite.h>
#include <..\\Projects\Snake\Tree.h>
#include <..\\Projects\Snake\Player.h>
#include <..\\Projects\Snake\Movement.h>
#include<..\\Projects\Snake\Cherry.h>
#include<..\\Projects\Snake\Hole.h>
#include<..\\Projects\Snake\Worm.h>
#include<..\\Projects\Snake\SnakeBody.h>
#include<..\\Projects\Snake\Object.h>
#include "Actions.h"
#include "Constants.h"
#include "Game.h"
#include "GameFont.h"
#include <string>
/**
*   @brief   Default Constructor.
*/


/**
*   @brief   Destructor.
*   @details Remove any non-managed memory and callbacks.
*/

SnakeGame::SnakeGame()
{}
SnakeGame::~SnakeGame()
{
	this->inputs->unregisterCallback(callback_id);

	if (player)
	{
		delete player;
		player = nullptr;
	} 
	if (hole)
	{
		delete hole;
		hole = nullptr;
	}
	if (my_tree)
	{
		delete my_tree;
		my_tree = nullptr;
	}
	if (my_cherry)
	{
		delete my_cherry;
		my_cherry = nullptr;
	}
	if (my_worm)
	{
		delete my_worm;
		my_worm = nullptr;
	}
	if (my_snake)
	{
		delete my_snake;
		my_snake = nullptr;
	}

	for (auto& font : GameFont::fonts)
	{
		delete font;
		font = nullptr;
	}
}
bool SnakeGame::Collision(int ax, int ay, int bx, int by)
{
	// 50 is the width and height of the player and cherry sprites
	if (ax < bx + 50 &&
		ax + 50 > bx &&
		ay < by + 50 &&
		ay + 50 > by)
	{
		return true;
	}
	else
	{
		return false;
	}

	
}


bool SnakeGame::HoleCollision(int dx, int dy, int cx, int cy)

{
	// 50 is the width and height of the player and hole sprites
	if (dx < cx + 50 &&
		dx + 50 > cx &&
		dy < cy + 50 &&
		dy + 50 > cy)
	{
		return true;
	}
	else
	{
		return false;
	}


}

bool SnakeGame::WormCollision(int fx, int fy, int ex, int ey)
{
	// 50 is the width and height of the player and hole sprites
	if (fx < ex + 50 &&
		fx + 50 > ex &&
		fy < ey + 50 &&
		fy + 50 > ey)
	{
		return true;
	}
	else
	{
		return false;
	}


}
bool SnakeGame::TreeCollision(int ix, int iy, int jx, int jy)
{
	// 50 is the width and height of the player and hole sprites
	if (ix < jx + 50 &&
		ix + 50 > jx &&
		iy < jy + 50 &&
		iy + 50 > jy)
	{
		return true;
	}
	else
	{
		return false;
	}


}



//bool SnakeGame::WallCollision(int hx, int hy, int gx, int gy)
//{
	// 50 is the width and height of the player and hole sprites
	//if (hx < gx + 50 &&
	//	hx + 50 > gx &&
	//	hy < gy + 50 &&
	//	hy + 50 > gy)
	///{
		//return true;
//	}
//	else
	//{
//		return false;
//	}


//}
/**
*   @brief   Initialises the game.
*   @details The game window is created and all assets required to
			 run the game are loaded. The input callback should also
			 be set in the initialise function. 
*   @return  True if the game initialised correctly.
*/
bool SnakeGame::init()
{
	width = WINDOW_WIDTH;
	height = WINDOW_HEIGHT;
	if (!initAPI())
	{
		return false;
	}
	my_tree = new Tree();
	my_tree->loadAvatar(renderer.get());
	//for (int i = 0; i < 10; i++)
	//{
	//	my_treeArray[i] = new Tree();
	//	my_treeArray[i]->loadAvatar(renderer.get());
	//	my_treeArray[i]->setPosX(rand() % Boardwidth);
	//	my_treeArray[i]->setPosY(rand() % Boardheight);


	//}

	my_cherry = new Cherry();
	my_cherry->loadAvatar(renderer.get());
	my_cherry->setPosX(rand() % Boardwidth);
	my_cherry->setPosY(rand() % Boardheight);

	

	hole = new Hole();
	hole->loadAvatar(renderer.get());
	hole->setPosX(500);
	hole->setPosY(500);

	my_worm = new Worm();
	my_worm->loadAvatar(renderer.get());
	my_worm->setPosX(rand() % Boardwidth);
	my_worm->setPosY(rand() % Boardheight);

	tail = 0;
	for (int i = 0; i < 10; i++)
	{
		my_snakeArray[i] = new SnakeBody();
		my_snakeArray[i]->loadAvatar(renderer.get());

		my_snakeArray[i]->setPosX(-100);
		my_snakeArray[i]->setPosY(-100);

	}

	player = new Player();
	player->loadAvatar(renderer.get());

	renderer->setClearColour(ASGE::COLOURS::BLACK);
	renderer->setWindowTitle("Snake - Game 2 SIMON HARRIS");
	renderer->setSpriteMode(ASGE::SpriteSortMode::IMMEDIATE);
	toggleFPS();

	// input callback function
	callback_id = this->inputs->addCallbackFnc(ASGE::EventType::E_KEY, &SnakeGame::input, this);
	
	// load fonts we need
	GameFont::fonts[0] = new GameFont(renderer->loadFont("..\\..\\Resources\\Fonts\\Comic.ttf", 42), "default", 42);
	if (GameFont::fonts[0]->id == -1)
	{
		return false;
	}
	
	return true;
}


/**
*   @brief   Should the game exit?
*   @details Has the renderer terminated or the game requesting to exit?
*   @return  True if the game should exit
*/
bool SnakeGame::shouldExit() const
{
	return (renderer->exit() || this->exit);
}

/**
*   @brief   Processes any key inputs and translates them to a GameAction
*   @details This function is added as a callback to handle the game's 
			 input. Key presseses are translated in to GameActions which 
			 are then processed by the main game loop.
*   @param   key is the key the action relates to
*   @param   action whether the key was released or pressed
*   @return  void
*/
void SnakeGame::input(ASGE::SharedEventData data) const
{
	auto key_event = static_cast<ASGE::KeyEvent*>(data.get());
	auto action = key_event->action;
	auto key = key_event->key;

	if (action == ASGE::KEYS::KEY_PRESSED)
	{
		if (key == ASGE::KEYS::KEY_ESCAPE)
		{
			game_action = GameAction::EXIT;
		}
		if (key == ASGE::KEYS::KEY_W)
		{
			game_movement = GameMovement::UP;
		}
		if (key == ASGE::KEYS::KEY_S)
		{
			game_movement = GameMovement::DOWN;
		}
		if (key == ASGE::KEYS::KEY_A)
		{
			game_movement = GameMovement::LEFT;
		}
		if (key == ASGE::KEYS::KEY_D)
		{
			game_movement = GameMovement::RIGHT;
		}
		if (key == ASGE::KEYS::KEY_ENTER)
		{
			game_action = GameAction::START;
		}
		if (key == ASGE::KEYS::KEY_P)
		{

			if (game_action != GameAction::PAUSE)
			{
				game_action == GameAction::PAUSE;
			}
			else if (game_action == GameAction::PAUSE)
			{
				game_action = GameAction::NONE;

			}
		}
		

		
	}
}


/**
*   @brief   Updates the scene
*   @details Prepares the renderer subsystem before drawing the
			 current frame. Once the current frame is has finished
			 the buffers are swapped accordingly and the image shown.
*   @return  void
*/
void SnakeGame::update(const ASGE::GameTime & time)
{
	
	my_game_time = time.game_time.count();

	if(my_game_time > last_update + 300)
	{
		// gamepad input is polled
		auto& gamepad = inputs->getGamePad(0);
		if (gamepad.is_connected &&
			gamepad.buttons[1])
		{
			game_action = GameAction::EXIT;
		}

		// run the game loop
		processGameActions();
		processGameMovement();

		// should we terminate the game?
		if (shouldExit())
		{
			signalExit();
		}

		if (start == true)
		{
			player->lastXY();
			if (up == true)
			{
				player->setPosY(-50.f);
				//sprite2->position[1] = sprite2->position[1] - 50.0f;
			//	player->setPosY(sprite2->position[1]);
				//sprite2->angle = 4.65;

			}
			if (down == true)
			{
				player->setPosY(+50.f);
				//sprite2->position[1] = sprite2->position[1] + 50.0f;
				//player->setPosY(sprite2->position[1]);
				//sprite2->angle = 1.55;
			}
			if (right == true)
			{
				player->setPosX(+50.f);
			//	sprite2->position[0] = sprite2->position[0] + 50.0f;
				//player->setPosX(sprite2->position[0]);
				//sprite2->angle = 0;
			}
			if (left == true)
			{
				player->setPosX(-50.f);
				//sprite2->position[0] = sprite2->position[0] - 50.0f;
			//	player->setPosX(sprite2->position[0]);
			//	sprite2->angle = 3.1;
			}
			if (pause == true)
			{
				right = false;
				left = false;
				up = false;
				down = false;
				pause = true;

			}
			for (int i = 0; i < tail; i++)
			{
				if (i == 0)
				{
					my_snakeArray[i]->setLPosX(my_snakeArray[i]->getPosx());
					my_snakeArray[i]->setLPosY(my_snakeArray[i]->getPosy());
					my_snakeArray[i]->setPosX(player->LPosX());
					my_snakeArray[i]->setPosY(player->LPosY());
				}
				else
				{
					my_snakeArray[i]->setLPosX(my_snakeArray[i]->getPosx());
					my_snakeArray[i]->setLPosY(my_snakeArray[i]->getPosy());
					my_snakeArray[i]->setPosX(my_snakeArray[i - 1]->LPosX());
					my_snakeArray[i]->setPosY(my_snakeArray[i - 1]->LPosY());
				}
				
			}
		
		}


		if (Collision(player->getPosx(), player->getPosy(), my_cherry->getPosx(), my_cherry->getPosy()))
		{
			score + 10;
			my_cherry->setPosX(rand() % Boardwidth);
			my_cherry->setPosY(rand() % Boardheight);
			tail++;
		}
		if (HoleCollision(player->getPosx(), player->getPosy(), hole->getPosx(), hole->getPosy()))
		{

			if (UnderGround != true)
			{

				UnderGround = true;
			}
			else if (UnderGround == true)
			{
				UnderGround = false;
				start = true;
			}
		
		}
		if (WormCollision(player->getPosx(), player->getPosy(), my_worm->getPosx(), my_worm->getPosy()))
		{
			score + 10;
			my_worm->setPosX(rand() % Boardwidth);
			my_worm->setPosY(rand() % Boardheight);
			tail++;
		}
		//if (TreeCollision(player->getPosx(), player->getPosy(), my_tree->getPosx(), my_tree->getPosy()))
		//{
			//GameOver = true;
			//game_action = GameAction::GAMEOVER;
	//	}
		for (int i = 0; i < 10; i++)
		{
			if (Collision(player->getPosx(), player->getPosy(), my_snakeArray[i]->getPosx(), my_snakeArray[i]->getPosy()))
			{
				game_action = GameAction::GAMEOVER;
			}			
		}
		last_update = my_game_time;
	}
}



/**
*   @brief   Renders the scene
*   @details Renders all the game objects to the current frame.
			 Once the current frame is has finished the buffers are 
			 swapped accordingly and the image shown.
*   @return  void
*/
void SnakeGame::render(const ASGE::GameTime &)
{
	if (GameOver == false)
	{
		if (start == false)
		{
			renderer->setFont(GameFont::fonts[0]->id == -1);
			renderer->renderText("SNAKE", 200, 325, 1.0, ASGE::COLOURS::RED);
			renderer->renderText("Press Enter to Start", 375, 325, 1.0, ASGE::COLOURS::BLUE);

		}
		if (start == true)
		{
			renderer->renderText("Score:", 200, 325, 1.0, ASGE::COLOURS::RED);
			player->getRenderer(renderer.get());	
			my_cherry->getRenderer(renderer.get());
			hole->getRenderer(renderer.get());
			//my_tree->getRenderer(renderer.get());

			renderer->setClearColour(ASGE::COLOURS::GREEN);
			for (int i = 0; i < tail; i++)
			{
				my_snakeArray[i]->getRenderer(renderer.get());
			}

		}
		if (UnderGround == true)
		{
			renderer->renderText("Score:", 600, 1000, 1.0, ASGE::COLOURS::RED);
			renderer->setClearColour(ASGE::COLOURS::DARKBLUE);
			my_worm->getRenderer(renderer.get());
			hole->getRenderer(renderer.get());
		}
	}

	if (GameOver == true)
	{
		renderer->setClearColour(ASGE::COLOURS::BLACK);
		renderer->renderText("Game Over", 375, 325, 1.0, ASGE::COLOURS::BLUE);
	}


}

/**
*   @brief   Processes the next game action
*   @details Uses the game action that was a direct result of 
*            user input. It allows input to processed in a different
             thread and the game actions performed in the main thread. 
*   @return  void
*/
void SnakeGame::processGameActions()
{
	if (game_action == GameAction::EXIT)
	{
		this->exit = true;
	}
	if (game_action == GameAction::START)
	{
		start = true;

	}
	if (game_action == GameAction::GAMEOVER)
	{
		GameOver = true;

	}
	if (game_action == GameAction::HOLE)
	{
		UnderGround = true;

	}

	game_action = GameAction::NONE;
}

void SnakeGame::processGameMovement()
{
	if (game_movement == GameMovement::UP)
	{
		down = false;
		up = true;
		right = false;
		left = false;
		pause = false;
		
	}
	if (game_movement == GameMovement::DOWN)
	{
		up = false;
		down = true;
		right = false;
		left = false;
		pause = false;
	}
	if (game_movement == GameMovement::LEFT)
	{
		left = true;
		up = false;
		down = false;
		right = false;
		pause = false;
	}
	if (game_movement == GameMovement::RIGHT)
	{
		right = true;
		left = false;
		up = false;
		down = false;
		pause = false;
	}
	if (game_action == GameAction::PAUSE)
	{
		right = false;
		left = false;
		up = false;
		down = false;
		pause = true;
	}
	

	game_action = GameAction::NONE;
}
