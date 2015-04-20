#pragma once

#include "stdafx.h"
#include "LearningParams.h";

bool LearningParams::debug = false;
int LearningParams::TrainingIterations = 800;
int LearningParams::EvalIterations = 100;
int LearningParams::TrainingExploration = 30;
int LearningParams::EvalExploration = 1;
float LearningParams::DiscountRate = 0.6f;

float LearningParams::LearningRate = 0.8f;
int LearningParams::MinTravel = 2;
int LearningParams::StuckFrames = 25;
//Store Reward Values.

std::map<std::string, float> LearningParams::rewards = std::map<std::string, float>{ { "distance", 2.f }, { "height", 8 }, { "hitenemy", -600.f }, { "WhipKill", 60.f }, { "StompKill", 60.f }, { "stuck", -20.f }, { "GoldGet", 40.f } };