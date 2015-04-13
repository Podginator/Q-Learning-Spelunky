#pragma once

//We need to represent the environment, and we could just use this storage class. 
class Environment
{
public:
	//Map Information 
	double spmap[42][34];
	double mapLiquids[42][34];
	double mapFog[42][34];
	double spiderWebs[42][34];
	double pushBlocks[42][34];
	double bats[42][34];

	//Spelunkers position information
	double startX;
	double startY;
	double currentX;
	double currentY; 
	double GetDistanceTravelled();

	//SpelunkerHealth
	int SpelunkerHealth;

	//Items
	bool udjatEye;
	bool coolGlasses;
	bool shopkeepersAngered;

	//Kills
	int kills;
	int stompKills;
	int whipKills;
};