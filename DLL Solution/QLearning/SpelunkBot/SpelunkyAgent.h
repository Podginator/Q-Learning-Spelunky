#pragma once
#include "SpelunkerState.h"
#include "Actions.h"
#include "ActionQLearning.h"
#include <vector>

class SpelunkyAgent
{
private:
	QTable qtable;
	//LParams learningParams;
	SpelunkerState state;
	enum Phase
	{
		INITIALIZE=0, LEARN, EVALUATE
	};
	Phase phase = Phase::INITIALIZE;
	int learningIteration = 0;
public:

	SpelunkyAgent();
	std::vector<Actions> getActions();
	void initialize()

};