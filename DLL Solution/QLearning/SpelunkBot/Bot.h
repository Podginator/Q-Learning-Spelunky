#ifdef SPELUNKBOT_EXPORTS
#define SPELUNKBOT_API extern "C" __declspec(dllexport)
#else
#define SPELUNKBOT_API extern "C" __declspec(dllimport)
#endif

#include "SpelunkerState.h";
#include "Environment.h";
#include "Actions.h";
#include "ActionQLearning.h"
#include "ActionEnum.h"
#include <map>
#include "stdafx.h"

#pragma region Vars

SpelunkerActions act;
Environment currentEnvironment;
SpelunkerState currentState;
QTable qTable;
ApiImport api;

int frames = 0;
unsigned long state;
float reward;
Actions prevAct;


#pragma endregion

#pragma region Function Declarations
double ConvertBoolToDouble(bool valToConvert);
char* ConvertBoolToChar(bool valToConvert);


void ResetBotVariables(void);


SPELUNKBOT_API double Initialise(void);

SPELUNKBOT_API double Update(double health, double botXPos, double botYPos);

SPELUNKBOT_API double GetHasGoal(void);
SPELUNKBOT_API double GetIsInAir(void);
SPELUNKBOT_API double GetIsJetpacking(void);
SPELUNKBOT_API double GetItemGoal(void);
SPELUNKBOT_API double GetPathCount(void);
SPELUNKBOT_API double GetTempID(void);
SPELUNKBOT_API double GetFogGoal(void);
SPELUNKBOT_API double GetEndGoal(void);
SPELUNKBOT_API double GetWaitTimer(void);
SPELUNKBOT_API double GetHeadingRight(void);
SPELUNKBOT_API double GetHeadingLeft(void);
SPELUNKBOT_API double GetGoRight(void);
SPELUNKBOT_API double GetGoLeft(void);
SPELUNKBOT_API double GetJump(void);
SPELUNKBOT_API double GetTargetX(void);
SPELUNKBOT_API double GetTargetY(void);
SPELUNKBOT_API double GetAttack(void);

