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
	Menu() {
        inputMenu = new InputMenu();
    }
    Menu(InputMenu& input, vector<Game*> mocksGame, string path) {
        inputMenu = &input;
        mocks = mocksGame;
        pathRanking = path;
    }
    void iniciar() {
        bool sortir = false;
        while (!sortir) {
            printer.netejaPantalla();
            printer.menuInici();
            int input = inputMenu->getInput();
            if (input == JUGAR) {
                //Demanar dificultat i nom
                printer.netejaPantalla();
                printer.nom();
                string nom = inputMenu->getNom();
                printer.netejaPantalla();
                printer.dificutat();
                int dificultat = inputMenu->getDificultat();
                while (dificultat == -1) {
                    printer.netejaPantalla();
                    printer.dificutat();
                    dificultat = inputMenu->getDificultat();
                }
                
                //Crear un objecte de Game
                Game* partida;
                if (mocks.size() == 0)
                    partida = new Game(dificultat, nom);
                else {
                    partida = mocks[i_mock];
                    i_mock++;
                }
                
                //Cridar a funció play() de Game
                partida->initTauler();
                int resultat = partida->play();
                
                //Si la partida no ha sigut abandonada, cridar a la funcio guardarPuntuacions
                if (resultat != -1)
                    guardarPuntuacio(nom, resultat, partida->getPuntuacio(), dificultat, pathRanking);

                //delete partida;
            }
            else if (input == RANKING) {
                vector<vector<string>> puntuacions = llegirRanking(pathRanking);
                printer.netejaPantalla();
                ranking.mostraRanking(puntuacions);
                inputMenu->espera();
            }
            else if (input == SORTIR) {
                sortir = true;
            }
        }
    }

    void guardarPuntuacio(string nom, int resultat, int puntuacio, int dificultat, string path) {
        ofstream file(path, ios::app);
        if (file.is_open()) {
            file << nom << " " << resultat << " " << puntuacio << " " << dificultat << "\n";
            file.close();
        }
    }
    
    vector<vector<string>> llegirRanking(string path) {
        ifstream file(path);
        vector<vector<string>> ranking;

        if (file.is_open()) {
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
            file.close();
        }

        return ranking;
    }
private:
    PrinterMenu printer;
    InputMenu* inputMenu;
    Ranking ranking;
    const int JUGAR = 1, RANKING = 2, SORTIR = 0, ERROR = -1;
    string pathRanking = "../files/Ranking.txt";
    vector<Game*> mocks;
    int i_mock = 0;
};
