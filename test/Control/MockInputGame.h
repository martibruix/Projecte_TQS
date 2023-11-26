#pragma once
#include "../../codi/View/InputGame.h"
#include <string>
#include <vector>
using namespace std;

class MockInputGame : public InputGame
{
public:
	MockInputGame(vector<vector<int>> instr) {
		instruccions = instr;
		index = 0;
	}
	vector<int> getInstruccio() override {
		vector<int> instruccio = instruccions[index];
		index++;
		return instruccio;
	}
	void espera() override {}
private:
	vector<vector<int>> instruccions;
	int index;
};