#pragma once
#include <map>
#include <string>

class LearningParams
{
public:
	static bool debug;
	static int TrainingIterations;
	static int EvalIterations;
	static int EvalExploration;
	static int TrainingExploration;
	static float DiscountRate;

	static float LearningRate; 
	static float ObservationWindow[];
	static int MinTravel;
	static int StuckFrames;
	//Store Reward Values.
	static std::map<std::string, float> rewards;



};