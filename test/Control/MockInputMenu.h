#pragma once
#include "../../codi/View/InputMenu.h"
#include <vector>
using namespace std;

class MockInputMenu : public InputMenu
{
	int getInput() override {
		int input = v_input[i];
		i++;
		return input;
	}
	string getNom() override {
		return "nom";
	}
	int getDificultat() override {
		return 1;
	}
	void espera() override {}
private:
	int i = 0;
	vector<int> v_input = { 1,1,1,2,-1,0 };
};