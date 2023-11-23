#pragma once
#include <string>
#include <iostream>
using namespace std;

class InputGame
{
public:
	InputGame() {};
	virtual vector<int> getInstruccio() {
		// Transformar la string a vector de ints: {instruccio, (pos_x), (pos_y)}
		// Valors per cada instrucció:
		//		OPEN: 0
		//		P: 1
		//		T: 2
		//		EXIT: 3
		//		Valor erroni: -1
		vector<int> instruccio;

		string instr;
		cin >> instr;

		if (instr == "OPEN") {
			instruccio.push_back(0);

			string x;
			string y;
			cin >> x >> y;

			int pos_x = stoi(x);
			int pos_y = stoi(y);
			instruccio.push_back(pos_x);
			instruccio.push_back(pos_y);
		}
		else if (instr == "P"){
			instruccio.push_back(1);

			string x;
			string y;
			cin >> x >> y;

			int pos_x = stoi(x);
			int pos_y = stoi(y);
			instruccio.push_back(pos_x);
			instruccio.push_back(pos_y);
		}
		else if (instr == "T") {
			instruccio.push_back(2);

			string x;
			string y;
			cin >> x >> y;

			int pos_x = stoi(x);
			int pos_y = stoi(y);
			instruccio.push_back(pos_x);
			instruccio.push_back(pos_y);
		}
		else if (instr == "EXIT") {
			instruccio.push_back(3);
		}
		else {
			instruccio.push_back(-1);
		}

		return instruccio;
	}
};