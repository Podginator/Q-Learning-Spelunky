#pragma once


class Environment
{
public:
	double spmap[42][34];
	double mapLiquids[42][34];
	double mapFog[42][34];
	// An array that contains how many spider webs each position contains
	double spiderWebs[42][34];
	double pushBlocks[42][34];
	double bats[42][34];

	bool udjatEye;
	bool coolGlasses;
	bool shopkeepersAngered;

	int kills;
	int stompKills;
	int whipKills;
};