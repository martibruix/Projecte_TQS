#pragma once
#include <string>
#include <iostream>
using namespace std;

class InputGame
{
public:
	InputGame() {};
	virtual string getInstruccio() {
		string missatge;
		cin >> missatge;
		return missatge;
	}
};