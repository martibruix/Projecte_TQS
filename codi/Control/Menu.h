#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include "../View/Printer.h"
#include "../View/InputMenu.h"
#include "../View/PrinterMenu.h"
#include "../View/Ranking.h"
#include "Game.h"
using namespace std;

class Menu
{
public:
	void iniciar() {

    }

    void guardarPuntuacio(string nom, int resultat, int puntuacio, int dificultat, string path) {
        ofstream file(path, ios::app);
        file << nom << " " << resultat << " " << puntuacio << " " << dificultat << "\n";
        file.close();
    }
    
    vector<vector<string>> llegirRanking(string path) {
        string linea;
        ifstream file(path);
        vector<vector<string>> ranking;
        vector<string> v_aux;
        int i = 0;
        while (!file.eof()) {
            string aux;
            file >> aux;
            v_aux.push_back(aux);
            if (i == 3) {
                ranking.push_back(v_aux);
                i = 0;
                v_aux.clear();
            }
            else {
                i++;
            }
        }

        return ranking;
    }
private:
    PrinterMenu printer;
    InputMenu inputMenu;
    Ranking ranking;
    const int JUGAR = 1, RANKING = 2, SORTIR = 0, ERROR = -1;
};
