#pragma once
#include <stdlib.h>;
#include <map>
#include "ActionEnum.h";


struct SpelunkerActions
{
public:
	size_t total_actions = 10;
	size_t getActionNum();
	
	void doAction(Actions action);
	Actions doRandomAction();
	void ResetBotVariables(void);

	SpelunkerActions();

	double _pathCount;
	double _tempID;
	double _targetX;
	double _targetY;

	bool _hasGoal;
	bool _spIsInAir;
	bool _spIsJetpacking;
	
	//Movement Actions
	bool _goRight;
	bool _goLeft;
	bool _jump;
	bool _attack;

	Actions GetAction(){ printf(map[action]); return action; };
	static std::string PrintAction(Actions action){ return map[action]; };

private:
	size_t actionNum;
	static std::map<Actions, const char *> map;
	Actions action; 
};