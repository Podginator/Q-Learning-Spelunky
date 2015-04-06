#pragma once


//We have to create a state that can be representated numerically, and create a wide range of numbers based on the state variables
//Incorporate environment, spelunker state, position x and y etc. 
//This will be passed to the qlearning.

class SpelunkerState
{
public:
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


	//UpdateMethod for State.
	/*Inputs from SpelunkBots.cpp
		WorldMap
		double spmap[X_NODES][Y_NODES];
		Liquids
		double mapLiquids[X_NODES][Y_NODES];
		Fog
		double mapFog[X_NODES][Y_NODES];

		// An array that contains how many spider webs each position contains
		Maybe Not needed
		double spiderWebs[X_NODES][Y_NODES];
		double pushBlocks[X_NODES][Y_NODES];
		Bats should be enemies.
		double bats[X_NODES][Y_NODES];

		//Contains list of Objects with x,y and type params and id.
		std::vector<collectableObject> collectablesList;
		std::vector<collectableObject> enemiesList;

		Could shorten this.
	*/

	//GetStateNum(How to?)

	//Direction

	//
};