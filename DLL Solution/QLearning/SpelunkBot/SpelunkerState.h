#pragma once
#include "Environment.h"
#include "LearningParams.h";
#include <map>
#include <bitset>
#include "ActionEnum.h"
#include "stdafx.h"
#include "Header.h"
#include "LearningParams.h"
#include "math.h"
//We have to create a state that can be representated numerically, and create a wide range of numbers based on the state variables
//Incorporate environment, spelunker state, position x and y etc. 
//This will be passed to the qlearning.

class SpelunkerState
{
public:
	ApiImport api;

	SpelunkerState()
	{
		currAct = Actions::RIGHT;
		ResetBytes();
	}
	
	Actions currAct;

	//Updates state with environmaent information.
	void Update(Environment &enviornment)
	{
		ResetBytes();

		//Assume, for now, goal is on the right.
		float distanceTravelled = enviornment.currentX - enviornment.startX;
		ddistance = distanceTravelled - lastDistance;

		lastDistance = distanceTravelled;

		if (ddistance == 0)
		{
			stuckcounter += 1; 
		}
		else
		{
			stuckcounter = 0;
			bits["isStuck"] = 0;
		}

		if (stuckcounter >= LearningParams::StuckFrames)
		{
			bits["isStuck"] = 1;
		}

		bits["Hit"] = enviornment.SpelunkerHealth < prevEnv.SpelunkerHealth ? 1 : 0;
		bits["OnGround"] = enviornment.inAir;

		GetDirection(enviornment);

		//Enemies; 
		int SpelunkerX = enviornment.currentX - 2;
		int SpelunkerY = enviornment.currentY - 2;
		for (int i = 0; i < 4; i++)
		{
			int X = SpelunkerX + i; 
			for (int j = 0; j < 4; j++)
			{
				int Y = SpelunkerY + j;
				enemies.push_back(api.IsEnemyInNode(X, Y, false));
			}
		}


	
		bits["StompKill"] = enviornment.stompKills > prevEnv.stompKills;
		bits["WhipKill"] = enviornment.whipKills > prevEnv.whipKills;


		for (int i = 0; i < 3; i++)
		{
			int x = bits["Left"] ? enviornment.currentX - 1 : enviornment.currentX + 1; 
			int y = enviornment.currentY - (i);
			obstacles[i] = enviornment.spmap[x][y];
		}
		
		//What the hell is this. Equal Operator isn't working.
		memcpy(prevEnv.spmap, enviornment.spmap, sizeof(double)* 42 * 34);
		memcpy(prevEnv.mapLiquids, enviornment.mapLiquids, sizeof(double)* 42 * 34);
		memcpy(prevEnv.mapFog, enviornment.mapFog, sizeof(double)* 42 * 34);
		memcpy(prevEnv.spiderWebs, enviornment.spiderWebs, sizeof(double)* 42 * 34);
		memcpy(prevEnv.pushBlocks, enviornment.pushBlocks, sizeof(double)* 42 * 34);
		memcpy(prevEnv.bats, enviornment.bats, sizeof(double)* 42 * 34);

		prevEnv.inAir = enviornment.inAir;
		prevEnv.kills = enviornment.kills;
		prevEnv.stompKills = enviornment.stompKills;
		prevEnv.whipKills = enviornment.whipKills;

		prevEnv.startX = enviornment.startX;
		prevEnv.startY = enviornment.startY;
		prevEnv.currentX = enviornment.currentX;
		prevEnv.currentY = enviornment.currentY;
		
		GenerateStateNumber();
	
	}

	void ResetBytes()
	{
		for (auto& keyVal : bits)
		{
			keyVal.second = 0;
		}

		enemies.clear();

		for (size_t i = 0; i < 3; i++)
		{
			obstacles[i] = 0;
		}
	}

	float GetReward()
	{
		float reward =
			(bits["isStuck"] ? 1 : 0) * LearningParams::rewards["stuck"] +
			ddistance * LearningParams::rewards["distance"] +
			(bits["Hit"] ? 1 : 0) * LearningParams::rewards["hitenemy"] +
			(bits["StompKill"] ? 1 : 0) * LearningParams::rewards["StompKill"] +
			(bits["WhipKill"] ? 1 : 0) * LearningParams::rewards["WhipKill"];

		return reward;
	}

	void GenerateStateNumber()
	{
		stateIndex = 0;

		std::string bitString = "";
		//First Generate New BitString
		for (auto& keyval : bits)
		{
			bitString += keyval.second ? "1" : "0";
		}

		for (size_t i = 0; i < 16; i++)
		{
			bitString += enemies[i] ? "1" : "0";
		}

		for (size_t i = 0; i < 3; i++)
		{
			bitString += obstacles[i] ? "1" : "0";
			std::cout << (obstacles[i] ? "1" : "0") << std::endl;
		}

		std::bitset<29> bits(bitString);

		stateIndex = bits.to_ulong();
	}

	unsigned long long GetStateNum()
	{
		return stateIndex;

	}

	Actions lastAct;

private:
	Environment prevEnv;
	unsigned long long stateIndex;
	float ddistance;
	float lastDistance;
	int stuckcounter;
	int prevHit;
	
	void GetDirection(Environment &env)
	{
		//Got the easier ones here. 
		if (ddistance != 0)
		{
			bits["Left"] = ddistance < 0 ? 1 : 0;
			bits["Right"] = ddistance > 0 ? 1 : 0;
			bits["Nothing"] = Actions::NOTHING ? 1 : 0;
		}
		else if (currAct != Actions::NOTHING)
		{
			bits["Left"] = currAct == Actions::LEFT || currAct == Actions::LEFT_JUMP || currAct == Actions::LEFT_WHIP ? 1 : 0;
			bits["Right"] = currAct == Actions::RIGHT || currAct == Actions::RIGHT_JUMP || currAct == Actions::RIGHT_WHIP ? 1 : 0;
		}
		else
		{
			bits["Left"] = lastAct == Actions::LEFT || lastAct == Actions::LEFT_JUMP || lastAct == Actions::LEFT_WHIP ? 1 : 0;
			bits["Right"] = lastAct == Actions::RIGHT || lastAct == Actions::RIGHT_JUMP || lastAct == Actions::RIGHT_WHIP ? 1 : 0;
		}


		//Descending
 		bits["Down"] = env.currentY > prevEnv.currentY;
		//Ascending.
		bits["Up"] = env.currentY < prevEnv.currentY;

		if (lastAct == Actions::NOTHING)
		{
			bits["Right"] = 1;
		}
	}

	//Just for 1 or 0 value states.
	std::map <std::string, bool> bits = std::map<std::string,bool>{
		//Start with Directions
		{ "Left", 0 },
		{ "Right", 0 },
		{ "Down", 0 },
		{ "Up", 0 },
		{ "NoAction", 0 },
		//Ground/Not
		{ "OnGround", 0 },
		{ "isStuck", 0 },
		//Then go with Hit/Not Hit/ Killed/NotKilled
		{ "Hit", 0 },
		{ "StompKill", 0 },
		{ "WhipKill", 0 }
	};

	//Track Enemies
	std::vector<bool> enemies;
	bool obstacles[3];
};