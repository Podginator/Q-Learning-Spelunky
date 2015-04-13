#pragma once

#include "LearningParams.h";

bool LearningParams::debug = false;
int LearningParams::TrainingIterations = 800;
int LearningParams::EvalIterations = 100;
float LearningParams::EvalExploration = 0.3f;
float LearningParams::TrainingExploration = 0.01f;
float LearningParams::DiscountRate = 0.6f;

float LearningParams::LearningRate = 0.8f;
int LearningParams::MinTravel = 2;
int LearningParams::StuckFrames = 25;
//Store Reward Values.

std::map<std::string, float> rewards = { { "distance", 2.f }, { "height", 8 }, { "hitenemy", -600.f }, { "WhipKill", 60.f }, { "StompKill", 60.f }, { "stuck", -20.f }, { "GoldGet", 40.f } };