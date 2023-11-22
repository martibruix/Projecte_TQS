#pragma once
#include <string>
#include <iostream>
using namespace std;

class InputGame
{
public:
	InputGame() {};
	virtual vector<int> getInstruccio() {
		string missatge;
		cin >> missatge;
		
		vector<int> instruccio;
		// Transformar la string a vector de ints: {instruccio, (pos_x), (pos_y)}
		// Valors per cada instrucció:
		//		OPEN: 0
		//		P: 1
		//		T: 2
		//		EXIT: 3
		//		Valor erroni: -1
		
		return instruccio;
	}
};