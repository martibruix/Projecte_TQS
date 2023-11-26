#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Printer
{
public:
    void tauler(vector<vector<char>> matriu) {
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
        cout << endl;
    }

    void missatgePartida(int flags, int punts) {
        cout << "Flags disponibles: " << flags << endl;
        cout << "Puntuacio: " << punts << " punts" << endl << endl;
        cout << "Introdueix una instruccio: ";
    }
    
    void finalPartida(bool abandonat, bool victoria, int punts) {
        if (abandonat) {
            cout << "SORTINT DEL JOC" << endl;
        } else {
            if (victoria) {
                cout << "HAS GUANYAT AMB UNA PUNTUACIO DE " << punts << " PUNTS" << endl;
            }
            else {
                cout << "HAS PERDUT AMB UNA PUNTUACIO DE " << punts << " PUNTS" << endl;
            }
        }
    }

    void netejaPantalla() {
        system("cls");
    }
};