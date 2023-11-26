#pragma once
#include <vector>
#include <time.h>
#include "Cell.h"
using namespace std;

class Board
{
public:
    Board(int alt, int amp, int min) {
        if (alt <= 0 || amp <= 0 || min <= 0 || alt*amp < min) {
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
    }
	~Board() {}

    int getAltura() { return altura; };
	int getAmplada() { return amplada; };
    vector<vector <Cell>> getMatriu() { return matriu; }
    int getMines() { return mines; }
    int getFlags() { return flags; }

    int setMatriu(vector<vector <Cell>> mat) {
        if (mat.size() == altura && mat[0].size() == amplada) {
            matriu = mat;
            return 0;
        }
        return -1;
    }

    void crearMines() {
        int num_mines = 0;
        srand(time(0));

        while (num_mines != mines) {
            int x = rand() % altura;
            int y = rand() % amplada;

            if (!matriu[x][y].esMina()) {
                matriu[x][y].setMina();
                num_mines++;
            }
        }
    }
    void calculSubjacents() {
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < amplada; j++) {
                if (!matriu[i][j].esMina()) {
                    int num_subjacents = 0;
                    if (i - 1 >= 0 && j - 1 >= 0) {
                        if (matriu[i - 1][j - 1].esMina())
                            num_subjacents++;
                    }
                    if (i - 1 >= 0) {
                        if (matriu[i - 1][j].esMina())
                            num_subjacents++;
                    }
                    if (i - 1 >= 0 && j + 1 < amplada) {
                        if (matriu[i - 1][j + 1].esMina())
                            num_subjacents++;
                    }
                    if (j - 1 >= 0) {
                        if (matriu[i][j - 1].esMina())
                            num_subjacents++;
                    }
                    if (j + 1 < amplada) {
                        if (matriu[i][j + 1].esMina())
                            num_subjacents++;
                    }
                    if (i + 1 < altura && j - 1 >= 0) {
                        if (matriu[i + 1][j - 1].esMina())
                            num_subjacents++;
                    }
                    if (i + 1 < altura) {
                        if (matriu[i + 1][j].esMina())
                            num_subjacents++;
                    }
                    if (i + 1 < altura && j + 1 < amplada) {
                        if (matriu[i + 1][j + 1].esMina())
                            num_subjacents++;
                    }
                    matriu[i][j].setSubjacents(num_subjacents);
                }
            }
        }
    }
    int posarFlags(int x, int y) {
        if (x < 0 || x >= altura || y < 0 || y >= amplada || flags == 0 || matriu[x][y].teFlag() || matriu[x][y].estaOberta())
            return -1;
        matriu[x][y].setFlag();
        flags--;
        return 0;
    }
    int treureFlags(int x, int y) {
        if (x < 0 || x >= altura || y < 0 || y >= amplada || !matriu[x][y].teFlag())
            return -1;
        matriu[x][y].setFlag();
        flags++;
        return 0;
    }
    int obrirCasella(int x, int y) {
        if (x < 0 || x >= altura || y < 0 || y >= amplada)
            return -2;
        int puntuacio = 0;
        if (!matriu[x][y].estaOberta() && !matriu[x][y].teFlag()) {
            matriu[x][y].setOberta();
            puntuacio += 10;
            if (matriu[x][y].esMina()) {
                return -1;
            }
            else {
                if (matriu[x][y].getSubjacents() == 0) {
                    if (x - 1 >= 0 && y - 1 >= 0) {
                        int p = obrirCasella(x - 1, y - 1);
                        if (p > 0)
                            puntuacio += p;
                    }
                    if (x - 1 >= 0) {
                        int p = obrirCasella(x - 1, y);
                        if (p > 0)
                            puntuacio += p;
                    }
                    if (x - 1 >= 0 && y + 1 < amplada) {
                        int p = obrirCasella(x - 1, y + 1);
                        if (p > 0)
                            puntuacio += p;
                    }
                    if (y - 1 >= 0) {
                        int p = obrirCasella(x, y - 1);
                        if (p > 0)
                            puntuacio += p;
                    }
                    if (y + 1 < amplada) {
                        int p = obrirCasella(x, y + 1);
                        if (p > 0)
                            puntuacio += p;
                    }
                    if (x + 1 < altura && y - 1 >= 0) {
                        int p = obrirCasella(x + 1, y - 1);
                        if (p > 0)
                            puntuacio += p;
                    }
                    if (x + 1 < altura) {
                        int p = obrirCasella(x + 1, y);
                        if (p > 0)
                            puntuacio += p;
                    }
                    if (x + 1 < altura && y + 1 < amplada) {
                        int p = obrirCasella(x + 1, y + 1);
                        if (p > 0)
                            puntuacio += p;
                    }
                }
            }
            return puntuacio;
        }
        else {
            return -2;
        }
    }
    int victoria() {
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < amplada; j++) {
                if (!matriu[i][j].esMina() && !matriu[i][j].estaOberta())
                    return 0;
            }
        }
        return 1;
    }
private:
    vector<vector <Cell>> matriu;
	int altura, amplada;
    int mines;
    int flags;
};