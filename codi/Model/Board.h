#include <vector>
#include "Cell.h"
using namespace std;

class Board
{
public:
	Board() { altura = 2; amplada = 2; mines = 2; flags = 2; };
    Board(int alt, int amp, int min) {
        if (alt <= 0 || amp <= 0) {
            altura = 1;
            amplada = 1;
        }
        else {
            altura = alt;
            amplada = amp;
        }

        matriu.resize(altura);
        for (int i = 0; i < altura; i++)
            matriu[i].resize(amplada);

        flags = min;
        mines = min;
    };
	~Board() {};
    int getAltura() { return altura; };
	int getAmplada() { return amplada; };
    vector<vector <Cell>> getMatriu() { return matriu; }
    int getMines() { return mines; }
    int getFlags() { return flags; }
    void crearMines();
    void calculSubjacents();
    void posarFlags();
    void treureFlags();
    void obrirCasella();
private:
    vector<vector <Cell>> matriu;
	int altura, amplada;
    int mines;
    int flags;
};