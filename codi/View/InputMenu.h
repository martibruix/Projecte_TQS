#pragma once
#include <string>
#include <iostream>
using namespace std;

class InputMenu
{
public:
	InputMenu() {};
	int getInput() {
		int input;
		
		if (cin >> input) {
			if (input < 0 || input > 2)
				input = -1;
		}
		else {
			cin.clear();
			input = -1;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return input;
	}
};