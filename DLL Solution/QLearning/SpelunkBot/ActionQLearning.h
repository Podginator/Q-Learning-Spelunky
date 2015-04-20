#pragma once

#include <random>
#include <map>
#include "ActionEnum.h";
#include "LearningParams.h"
// basic file operations
#include <iostream>
#include <fstream>
#include "Actions.h"

class QTable
{
public:
	int random; 
	QTable()
	{
		qtable = std::map<unsigned long, std::map<Actions, float>>{};
	}
	//int getNextAct(unsigned long state);
	Actions getBestAct(unsigned long state);
	Actions GetNextAct(unsigned long state);
	void updateQValue(float reward, unsigned long currentState);
	std::map<Actions, float> actqVal(unsigned long state);
	void getInitial(unsigned long state);
	std::map<unsigned long, std::map<Actions, float>> getQTable();
	void saveFile()
	{

		std::ofstream myfile;
		myfile.open("C:\\Users\\Podginato\\Documents\\GitHub\\Q-Learning-Spelunky\\example.txt");
		for (auto& kv : qtable )
		{
			for (auto& kvv : kv.second)
			{
				myfile << kv.first << "[" << SpelunkerActions::PrintAction(kvv.first) << "]" << kvv.second << std::endl;
			}
		}
		myfile.close();
	}
	
	unsigned long prevState;
	Actions prevAct;
	

private:
	std::map<unsigned long, std::map<Actions, float>> qtable;
	


};