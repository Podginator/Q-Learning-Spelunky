#pragma once
#include "Environment.h"

//We have to create a state that can be representated numerically, and create a wide range of numbers based on the state variables
//Incorporate environment, spelunker state, position x and y etc. 
//This will be passed to the qlearning.

class SpelunkerState
{
public:

	SpelunkerState()
	{

	}

	//Updates state with environment information.
	void Update(Environment enviornment)
	{
		
	}
	//Spelunker Direction

	//Spelunker X_Y

	//Is Stuck

	//OnGround, CanJump (Implemented already, I think) global.canJumpRight or global.canJumpGrabRight

	//EnemiesAround(Viewing Window)

	//Enemy
	//LastEnemy

	//EnemyKilled(inframe)

	//Obstacles/Environment

	//Gaps?

	//Spelunker HP / Items? 


	//StateNumber (Unique Identifier)


	//GetStateNum(How to?)

	//Direction
};