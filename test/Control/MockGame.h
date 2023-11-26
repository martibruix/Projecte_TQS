#pragma once
#include "../../codi/Control/Game.h"
using namespace std;

class MockGame : public Game
{
public:
	MockGame(int dif, string name, InputGame& input, vector<vector<Cell>> matriu) : Game(dif, name, input) {
		Board* board = getTauler();
		board->setMatriu(matriu);
	}
	
	void initTauler() override {}
};