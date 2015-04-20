// SpelunkBot.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Bot.h"
#include "Actions.h"

#pragma region Defines

// Use for functions that take either pixel or node coordinates
#define NODE_COORDS 0
#define PIXEL_COORDS 1

// Nodes in the x and y axes
#define Y_NODES 34
#define X_NODES 42

// Number of pixels in each node
#define PIXELS_IN_NODES 16

// Variable types - useful for when calling UpdatePlayerVariables()
#define BOOLEAN 0
#define DOUBLE 1
#define STRING 2

#pragma endregion

#pragma region Setup


SPELUNKBOT_API double Initialise(void)
{
	act.ResetBotVariables();
	return 1;
}

#pragma endregion

#pragma region Bot Logic

SPELUNKBOT_API double Update(double hp, double botXPos, double botYPos)
{
	if (frames == 4)
	{


		//Get Environment.
		api.GetEnvironment(currentEnvironment);
		currentEnvironment.SpelunkerHealth = hp;
		currentEnvironment.currentX = botXPos;
		currentEnvironment.currentY = botYPos;
		currentState.Update(currentEnvironment);
		act.ResetBotVariables();
		//QTable
		reward = currentState.GetReward();

		
		qTable.updateQValue(reward, state);
		prevAct = qTable.GetNextAct(state);
		qTable.prevAct = prevAct;
		act.doAction(prevAct);
		state = currentState.GetStateNum();
		
		frames = 0;
	}
	else
	{
		frames++;
		qTable.saveFile();

	}

	return 1;
}


#pragma endregion

#pragma region Get functions for GM

double ConvertBoolToDouble(bool valToConvert)
{
	if (valToConvert)
	{
		return 1;
	}
	return 0;
}
char* ConvertBoolToChar(bool valToConvert)
{
	if (valToConvert)
	{
		return "1";
	}
	return "0";
}
SPELUNKBOT_API double GetHasGoal(void)
{
	return ConvertBoolToDouble(act._hasGoal);
}
SPELUNKBOT_API double GetIsInAir(void)
{
	return ConvertBoolToDouble(act._spIsInAir);
}
SPELUNKBOT_API double GetIsJetpacking(void)
{
	return ConvertBoolToDouble(act._spIsJetpacking);
}

SPELUNKBOT_API double GetGoRight(void)
{
	return ConvertBoolToDouble(act._goRight);
}
SPELUNKBOT_API double GetGoLeft(void)
{
	return ConvertBoolToDouble(act._goLeft);
}
SPELUNKBOT_API double GetJump(void)
{
	return ConvertBoolToDouble(act._jump);
}
SPELUNKBOT_API double GetAttack(void)
{
	return ConvertBoolToDouble(act._attack);
}

#pragma endregion