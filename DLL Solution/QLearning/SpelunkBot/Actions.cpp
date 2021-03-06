#pragma once

#include "stdafx.h";
#include "Actions.h";


SpelunkerActions::SpelunkerActions()
{
	ResetBotVariables();
}

void SpelunkerActions::ResetBotVariables()
{
	_pathCount = 0;
	_tempID = 0;
	_targetX = 0;
	_targetY = 0;

	_hasGoal = false;
	_spIsInAir = false;
	_spIsJetpacking = false;

	//Movement Actions
	_goRight = false;
	_goLeft = false; 
	_jump = false;
	_attack = false;
}

Actions SpelunkerActions::doRandomAction()
{
	Actions res = Actions::NOTHING;
	int actNum = rand() % total_actions;

	ResetBotVariables();

	switch (actNum)
	{
	case 1:
		_goLeft = true;
		res = Actions::LEFT;
		break;
	case 2: 
		_goRight = true;
		res = Actions::RIGHT;
		break;
	case 3: 
		_jump = true;
		res = Actions::JUMP;
		break;
	case 4: 
		res = Actions::NOTHING;
		break;
	case 5:
		_jump = true;
		_goRight = true;
		res = Actions::RIGHT_JUMP;
		break;
	case 6: 
		_jump = true;
		_goLeft = true;
		res = Actions::LEFT_JUMP;
		break;
	case 7: 
		_attack = true;
		res = Actions::WHIP;
		break;
	case 8: 
		_jump = true;
		_attack = true;
		res = Actions::LEFT_WHIP;
		break;
	case 9: 
		_goRight = true;
		_attack = true;
		res = Actions::RIGHT_WHIP;
		break;
	case 10:
		_jump = true;
		_attack = true;
		res = Actions::JUMP_WHIP;
		break;
	}

	action = res;

	return res;
}

void SpelunkerActions::doAction(Actions action)
{
	switch (action)
	{
	case Actions::RIGHT:
		_goRight = true;
		this->action = Actions::RIGHT;
		break;
	case Actions::LEFT:
		_goLeft = true;
		this->action = Actions::LEFT;
		break;
	case Actions::JUMP:
		_jump = true;
		this->action = Actions::JUMP;
		break;
	case Actions::JUMP_WHIP:
		_jump = true;
		_attack = true;
		this->action = Actions::JUMP_WHIP;
		break;
	case Actions::LEFT_JUMP:
		_goLeft = true;
		_jump = true;
		this->action = Actions::LEFT_JUMP;
		break;
	case Actions::RIGHT_JUMP:
		_goRight = true;
		_jump = true;
		this->action = Actions::RIGHT_JUMP;
		break;
	case Actions::RIGHT_WHIP:
		_goRight = true;
		_attack = true;
		this->action = Actions::RIGHT_WHIP;
		break;
	case Actions::LEFT_WHIP:
		_goLeft = true;
		_attack = true;
		this->action = Actions::LEFT_WHIP;
		break;
	case Actions::WHIP:
		_attack = true;
		this->action = Actions::WHIP;
		break;
	case Actions::NOTHING:
		this->action = Actions::NOTHING;
		break;
	}

}

std::map<Actions, const char *> SpelunkerActions::map = std::map<Actions, const char *>{
	{ Actions::NOTHING, "Nothing" },
	{ Actions::LEFT, "L" },
	{ Actions::RIGHT, "R" },
	{ Actions::JUMP, "J" },
	{ Actions::WHIP, "W" },
	{ Actions::LEFT_JUMP, "LJ" },
	{ Actions::RIGHT_JUMP, "RJ" },
	{ Actions::LEFT_WHIP, "LW" },
	{ Actions::RIGHT_WHIP, "RW" },
	{ Actions::JUMP_WHIP, "JW" }
};

