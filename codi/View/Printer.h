#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Printer
{
public:
    template<const int row, const int col>
    void Taulell(int fila, int columna, int flags, int punts, string cells[][col]) { /* string (*cells)[columna] */
        string index     = "   ";
        string separator = "  +";
        for (int j = 0; j < columna; j++) {
            index     += " " + to_string(j + 1) + "  ";
            separator += " - +";
        }
        cout << index << endl;
        cout << separator << endl;
        for (int i = 0; i < fila; i++) {
            string str = to_string(i + 1) + " |";
            for (int j = 0; j < columna; j++) { 
                str += " " + cells[i][j] + " |"; 
            }
            cout << str << endl;
            cout << separator << endl;
        }
        cout << "Flags disponibles: " << flags << endl;
        cout << "Puntuació: " << punts << " punts" << endl;
    }

    void tauler(vector<vector<char>> matriu) {

    }
    
    void finalPartida(bool abandonat, bool victoria, int punts) {
        if (abandonat) {
            cout << "SORTINT DEL JOC" << endl;
        } else {
            if (victoria) {
                cout << "HAS GUANYAT AMB UNA PUNTUACIÓ DE " << punts << " PUNTS" << endl;
            }
            else {
                cout << "HAS PERDUT AMB UNA PUNTUACIÓ DE " << punts << " PUNTS" << endl;
            }
        }
    }
};