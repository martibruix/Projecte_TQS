#pragma once
#include "../Model/Board.h"
#include <string>
#include "../View/InputGame.h"
#include "../View/Printer.h"
using namespace std;

class Game
{
public:
    Game(int dif, string name) {
        dificultat = dif;
        nom = name;
        puntuacio = 0;
        if (dif == FACIL) {
            tauler = new Board(6, 6, 7);
        }
        else if (dif == MITJA) {
            tauler = new Board(8, 8, 10);
        }
        else if (dif == DIFICIL) {
            tauler = new Board(15, 15, 35);
        }
        else {
            tauler = new Board(6, 6, 7);
            dificultat = FACIL;
        }
        inputGame = new InputGame();
    }
    Game(int dif, string name, InputGame& input) {
        dificultat = dif;
        nom = name;
        puntuacio=0;
        if (dif == FACIL){
            tauler = new Board(6, 6, 7);
        }
        else if (dif == MITJA){
            tauler = new Board(8, 8, 10);
        }
        else if (dif == DIFICIL){
            tauler = new Board(15, 15, 35);
        }
        else {
            tauler = new Board(6, 6, 7);
            dificultat = FACIL;
        }
        inputGame = &input;
    }
    virtual void initTauler() {
        tauler->crearMines();
        tauler->calculSubjacents();
    }
    int play(){
        bool mort = false, victoria = false, sortir = false;
        
        do {
            printer.netejaPantalla();
            printer.tauler(printMatriu());
            printer.missatgePartida(tauler->getFlags(), puntuacio);
            vector<int> instruccio = inputGame->getInstruccio();
            
            if (instruccio[0] == OPEN) {
                int punts = tauler->obrirCasella(instruccio[1], instruccio[2]);
                if (punts == -1) {
                    mort = true;
                }
                else if (punts > -1) {
                    puntuacio += punts;
                    if (tauler->victoria())
                        victoria = true;
                }
            }
            else if (instruccio[0] == POSAR_FLAG) {
                tauler->posarFlags(instruccio[1], instruccio[2]);
            }
            else if (instruccio[0] == TREURE_FLAG) {
                tauler->treureFlags(instruccio[1], instruccio[2]);
            }
            else if (instruccio[0] == EXIT) {
                sortir = true;
            }
        } while (!mort && !victoria && !sortir);

        printer.netejaPantalla();
        printer.tauler(printMatriu());
        printer.finalPartida(sortir, victoria, puntuacio);
        inputGame->espera();

        if (victoria)
            return 1;
        if (mort)
            return 0;
        return -1;
    }

    char getCharMatriu(bool mina, bool oberta, bool flag, int subjacents) {
        if (subjacents < 0 || subjacents > 8)
            return 'E';
        if (oberta && flag)
            return 'E';
        if (mina && subjacents > 0)
            return 'E';
        if (flag)
            return 'F';
        else if (!oberta)
            return ' ';
        else if (mina)
            return 'X';
        else {
            string aux = to_string(subjacents);
            return *aux.c_str();
        }
    }
    
    vector<vector<char>> printMatriu(){
        vector<vector<char>> matriuFinal;
        matriuFinal.resize(tauler->getAltura());
        for (int i = 0; i < matriuFinal.size(); i++)
            matriuFinal[i].resize(tauler->getAmplada());

        vector<vector<Cell>> matriuBoard = tauler->getMatriu();
        for (int i = 0; i < matriuFinal.size(); i++) {
            for (int j = 0; j < matriuFinal[i].size(); j++) {
                matriuFinal[i][j] = getCharMatriu(matriuBoard[i][j].esMina(), matriuBoard[i][j].estaOberta(), matriuBoard[i][j].teFlag(), matriuBoard[i][j].getSubjacents());
            }
        }

        return matriuFinal;
    }
    Board* getTauler() { return tauler; }
    int getPuntuacio() { return puntuacio; }
    int getDificultat() { return dificultat; }
    string getNom() { return nom; }
private:
    Board *tauler;
    int puntuacio;
    int dificultat;
    string nom;
    const int FACIL = 1, MITJA = 2, DIFICIL = 3;
    const int OPEN = 0, POSAR_FLAG = 1, TREURE_FLAG = 2, EXIT = 3, ERROR = -1;
    InputGame* inputGame;
    Printer printer;
};

