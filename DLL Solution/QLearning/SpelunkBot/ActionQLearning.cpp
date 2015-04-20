#pragma once

#include "stdafx.h"
#include "ActionQLearning.h"
#include "Actions.h"

std::map<Actions, float> QTable::actqVal(unsigned long state)
{
	if (qtable.count(state) == 0)
	{
		getInitial(state);
		return qtable[state];
	}
	else
	{
		return qtable[state];
	}
}

Actions QTable::GetNextAct(unsigned long state)
{
	//prevState = state;
	Actions act;
	int random = rand() % 101;
	if (random < LearningParams::TrainingExploration) {
		act = static_cast<Actions>(int(rand() % 10));
	}
	else {
		act = getBestAct(state);
	}
	return act;
}

Actions QTable::getBestAct(unsigned long state)
{
	std::map<Actions, float> rewards = actqVal(state);

	if (rewards.size() == 0)
	{
		//Throw exception, no rewards
		return Actions::NOTHING;
	}
	else
	{
		float rewardVal = -999999999.f;
		Actions action;
		int i = 0;
		std::string Rewards = "";
		for (auto& keyval : rewards)
		{
			i++;
			//SpelunkerActions::PrintAction(keyval.first);
			if (keyval.second > rewardVal)
			{
				rewardVal = keyval.second;
				action = keyval.first;
			}
		}
		return action;
	}
}


void QTable::getInitial(unsigned long state)
{
	qtable[state] = std::map<Actions, float> {
		{ Actions::JUMP, 0 },
		{ Actions::JUMP_WHIP, 0 },
		{ Actions::LEFT, 0 },
		{ Actions::LEFT_JUMP, 0 },
		{ Actions::LEFT_WHIP, 0 },
		{ Actions::NOTHING, -20},
		{ Actions::RIGHT, 0 },
		{ Actions::RIGHT_JUMP, 0},
		{ Actions::RIGHT_WHIP, 0},
		{ Actions::WHIP, 0 }
	};
}

void QTable::updateQValue(float reward, unsigned long state)
{
	std::map<Actions, float> prevQs = actqVal(prevState);
	float prevReward = prevQs[prevAct];

	Actions bestAct = getBestAct(state);
	float maxQ = actqVal(state)[bestAct];

	float alpha = 0.15;

	float  newQ = (1 - alpha) * prevReward + alpha * (reward + LearningParams::DiscountRate * maxQ);
 
	qtable[prevState][prevAct] = newQ;

	prevState = state;
	
	std::cout << "MaxQ"  <<"STATE:  " << prevState << " PrevAct: " << SpelunkerActions::PrintAction(prevAct) << " : " << newQ << std::endl;
}

std::map<unsigned long, std::map<Actions, float>> QTable::getQTable()
{
	return qtable;
}