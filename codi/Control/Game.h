#include "../Model/Board.h"
#include <string>

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
        return matriuFinal = {
            {' ', 'F', '0', ' ', ' ', ' '},
            {'3', ' ', '1', ' ', ' ', ' '},
            {'X', 'F', 'F', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' '}
        };
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

