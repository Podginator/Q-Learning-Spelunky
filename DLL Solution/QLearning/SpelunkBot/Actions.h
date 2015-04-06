#pragma once

enum Actions{ NOTHING, LEFT, RIGHT, JUMP, WHIP, LEFT_JUMP, RIGHT_JUMP, LEFT_JUMP, RIGHT_WHIP, LEFT_WHIP, JUMP_WHIP };

struct SpelunkerActions
{
public:
	size_t total_actions = 11;
	size_t getActionNum();
	void doAction(Actions action);
private:
	size_t actionNum;
	Actions action; 
};