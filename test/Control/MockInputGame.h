#pragma once
#include "../../codi/View/InputGame.h"
#include <string>
#include <vector>
using namespace std;

class MockInputGame : public InputGame
{
public:
	MockInputGame(vector<string> instr) {
		instruccions = instr;
		index = 0;
	}
	string getInstruccio() override {
		string instruccio = instruccions[index];
		index++;
		return instruccio;
	}
private:
	vector<string> instruccions;
	int index;
};