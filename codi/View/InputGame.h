#pragma once
#include <string>
#include <iostream>
using namespace std;

class InputGame
{
public:
	virtual string getInstruccio() {
		string missatge;
		cin >> missatge;
		return missatge;
	}
};