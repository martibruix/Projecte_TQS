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
			int x;
			int y;
			if (cin >> x >> y) {
				instruccio.push_back(0);
				instruccio.push_back(x);
				instruccio.push_back(y);
			}
			else {
				cin.clear();
				instruccio.push_back(-1);
			}
		}
		else if (instr == "P"){
			int x;
			int y;
			if (cin >> x >> y) {
				instruccio.push_back(1);
				instruccio.push_back(x);
				instruccio.push_back(y);
			}
			else {
				cin.clear();
				instruccio.push_back(-1);
			}
		}
		else if (instr == "T") {
			int x;
			int y;
			if (cin >> x >> y) {
				instruccio.push_back(2);
				instruccio.push_back(x);
				instruccio.push_back(y);
			}
			else {
				cin.clear();
				instruccio.push_back(-1);
			}
		}
		else if (instr == "EXIT") {
			instruccio.push_back(3);
		}
		else {
			instruccio.push_back(-1);
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return instruccio;
	}
};