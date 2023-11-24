#pragma once
#include <vector>
#include <iostream>
using namespace std;

class PrinterMenu
{
public:
    void menuInici() {
        cout << "==========" << endl;
        cout << "BUSCAMINES" << endl;
        cout << "==========" << endl;
        cout << endl;
        cout << "1- Jugar" << endl;
        cout << "2- Ranking" << endl;
        cout << endl;
        cout << "0- Sortir" << endl;
        cout << endl;
        cout << "Selecciona una opció: " << endl;
    }
    
    void dificutat() {
        cout << "==========" << endl;
        cout << "DIFICULTAT" << endl;
        cout << "==========" << endl;
        cout << endl;
        cout << "1- Facil" << endl;
        cout << "2- Intermig" << endl;
        cout << "3- Dificil" << endl;
        cout << endl;
        cout << "Selecciona una opció: " << endl;
    }
};