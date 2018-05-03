#pragma once
#include <string>
#include <atomic>

/** @file Actions.h
@brief   The Actions file define a thread safe game action
@details GameActions are stored here as well as a thread safe
GameAction variable, which has external linkage.
*/


/** @enum GameAction
*   @brief is a strongly typed enum class representing the next game action
*/
enum class GameMovement
{
	NONE,LEFT,RIGHT,UP,DOWN
};

extern std::atomic<GameMovement> game_movement;