#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Printer
{
public:
    void tauler(vector<vector<char>> matriu, int flags, int punts) {
        string index = "   ";
        string separator = "  +";
        for (int j = 0; j < matriu[0].size(); j++) {
            index += " " + to_string(j) + "  ";
            separator += " - +";
        }
        cout << index << endl;
        cout << separator << endl;
        for (int i = 0; i < matriu.size(); i++) {
            string str = to_string(i) + " |";
            for (int j = 0; j < matriu[i].size(); j++) {
                string aux(1, matriu[i][j]);
                str += " " + aux + " |";
            }
            cout << str << endl;
            cout << separator << endl;
        }
        cout << "Flags disponibles: " << flags << endl;
        cout << "Puntuació: " << punts << " punts" << endl << endl;
        cout << "Introdueix una instrucció: ";
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