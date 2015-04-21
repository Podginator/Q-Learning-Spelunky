#pragma once

#include <random>
#include <map>
#include "ActionEnum.h";
#include "LearningParams.h"
// basic file operations
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


#include "Actions.h"

class QTable
{
public:
	int random; 
	QTable()
	{
		qtable = std::map<unsigned long, std::map<Actions, float>>{};
		loadFile();
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
		myfile.open("C:\\Users\\Podginato\\Documents\\GitHub\\Q-Learning-Spelunky\\QTable.txt");
		for (auto& kv : qtable )
		{
			for (auto& kvv : kv.second)
			{
				myfile << kv.first << " " << kvv.first << " " << kvv.second << std::endl;
			}
		}
		myfile.close();
	}

	void loadFile()
	{
		std::vector <std::vector <std::string> > data;
		std::ifstream infile;
		infile.open("C:\\Users\\Podginato\\Documents\\GitHub\\Q-Learning-Spelunky\\QTable.txt");

		while (infile)
		{
			std::string s;
			if (!getline(infile, s)) break;

			std::istringstream ss(s);
			std::vector <std::string> record;

			while (ss)
			{
				std::string s;
				if (!getline(ss, s, ' ')) break;
				record.push_back(s);
			}
			data.push_back(record);
		}
		

		for (auto& datum : data)
		{
			qtable[strtoul(datum[0].c_str(), NULL, 0)].insert(std::pair<Actions,float>((Actions)atoi(datum[1].c_str()), std::stof(datum[2])));
		}
	}
	
	unsigned long prevState;
	Actions prevAct;
	

private:
	std::map<unsigned long, std::map<Actions, float>> qtable;
	


};