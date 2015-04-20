#pragma once

#include <vector>;

//We need to represent the environment, and we could just use this storage class. 

struct collectableObject {
	int type;
	int id;
	double x;
	double y;
};

struct enemyObject {
	int type;
	int id;
	double x;
	double y;
	double directionFacing;
	double status;
};


class Environment
{
public:

	Environment(const Environment &env)
	{
		copy(env);
	}

	Environment()
	{
	}

	Environment& operator= (Environment&& other)
	{
		copy(other);
		return *this;
	}

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

	bool inAir;


	//Kills
	int kills;
	int stompKills;
	int whipKills;

private:
	void copy(const Environment &env)
	{
		memcpy(spmap, env.spmap, sizeof(double)* 42 * 34);
		memcpy(mapLiquids, env.mapLiquids, sizeof(double)* 42 * 34);
		memcpy(mapFog, env.mapFog, sizeof(double)* 42 * 34);
		memcpy(spiderWebs, env.spiderWebs, sizeof(double)* 42 * 34);
		memcpy(pushBlocks, env.pushBlocks, sizeof(double)* 42 * 34);
		memcpy(bats, env.bats, sizeof(double)* 42 * 34);

		//collectablesList = std::vector<collectableObject>(env.collectablesList);
		//enemiesList = std::vector<collectableObject>(env.enemiesList);
		inAir = env.inAir;
		kills = env.kills;
		stompKills = env.stompKills;
		whipKills = env.whipKills;

		startX = env.startX;
		startY = env.startY;
	}



};