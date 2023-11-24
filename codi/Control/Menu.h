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
    
    vector<vector<string>> llegirRanking() {

    }
private:
    PrinterMenu printer;
    InputMenu inputMenu;
    Ranking ranking;
    const int JUGAR = 1, RANKING = 2, SORTIR = 0, ERROR = -1;
};
