#include <vector>
#include "Cell.h"
using namespace std;

class Board
{
public:
    Board(int alt, int amp, int min) {
        if (alt <= 0 || amp <= 0 || min < 0 || alt*amp < min) {
            altura = 2;
            amplada = 2;
            flags = 2;
            mines = 2;
            matriu.resize(2);
            for (int i = 0; i < 2; i++)
                matriu[i].resize(2);
        }
        else {
            altura = alt;
            amplada = amp;
            flags = min;
            mines = min;
            matriu.resize(altura);
            for (int i = 0; i < altura; i++)
                matriu[i].resize(amplada);
        }
    };
	~Board() {};
    int getAltura() { return altura; };
	int getAmplada() { return amplada; };
    vector<vector <Cell>> getMatriu() { return matriu; }
    int getMines() { return mines; }
    int getFlags() { return flags; }
    void crearMines();
    void calculSubjacents();
    int posarFlags(int x, int y);
    int treureFlags(int x, int y);
    int obrirCasella(int x, int y);
private:
    vector<vector <Cell>> matriu;
	int altura, amplada;
    int mines;
    int flags;
};