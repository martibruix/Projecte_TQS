#pragma once
#include <string>
#include <iostream>
using namespace std;

class InputMenu
{
public:
	InputMenu() {};
	virtual int getInput() {
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
	virtual string getNom() {
		string nom;
		cin >> nom;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return nom;
	}
	virtual int getDificultat() {
		int dificultat;
		if (cin >> dificultat) {
			if (dificultat < 1 || dificultat > 3)
				dificultat = -1;
		}
		else {
			cin.clear();
			dificultat = -1;
		}
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return dificultat;
	}
	virtual void espera() {
		cout << endl << endl << "Prem Enter per continuar" << endl;
		char a;
		cin.get(a);
	}
};