#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Ranking
{
public:
	void Registre() {
        cout << "Introdueix el teu nom per registrarlo en el ranking: " << endl;
    }
    void MostraRanking(vector<vector<string>> ranking) {
        cout << "==================" << endl;
        cout << "RANKING BUSCAMINES" << endl;
        cout << "==================" << endl;
        cout << "JUGADOR" << setw(30) << "PUNTUACIO" << setw(10) << "VICTORIES" << endl;
        /*printf("%-40s %-10s %-30s", "JUGADOR", "PUNTUACIO", "VICTORIES");*/
        cout << endl;
        for (vector<string> jugador : ranking) {
            printf("%-40s %-10s %-30s", jugador[0].c_str(), jugador[1].c_str(), jugador[2].c_str());
            cout << endl;
        }
        cout << endl;
    }
};