#include "../Model/Board.h"
#include <string>
using namespace std;

class Game
{
public:
    Game(int dif, string name){
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
    }
    int play(){

    }
    vector<vector<char>> printMatriu(){
        vector<vector<char>> matriuFinal;
        matriuFinal.resize(tauler->getAltura());
        for (int i = 0; i < matriuFinal.size(); i++)
            matriuFinal[i].resize(tauler->getAmplada());

        vector<vector<Cell>> matriuBoard = tauler->getMatriu();
        for (int i = 0; i < matriuFinal.size(); i++) {
            for (int j = 0; j < matriuFinal[i].size(); j++) {
                if (matriuBoard[i][j].teFlag())
                    matriuFinal[i][j] = 'F';
                else if (!matriuBoard[i][j].estaOberta())
                    matriuFinal[i][j] = ' ';
                else if (matriuBoard[i][j].esMina())
                    matriuFinal[i][j] = 'X';
                else {
                    string aux = to_string(matriuBoard[i][j].getSubjacents());
                    matriuFinal[i][j] = *aux.c_str();
                }
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
    const int FACIL=1, MITJA=2, DIFICIL=3;
};

