#pragma once
#include <map>

class LearningParams
{
public:
	static bool debug;
	static int TrainingIterations;
	static int EvalIterations;
	static float EvalExploration;
	static float TrainingExploration;
	static float DiscountRate;

	static float LearningRate; 
	static int MinTravel;
	static int StuckFrames;
	//Store Reward Values.
	static std::map<std::string, float> rewards;

};