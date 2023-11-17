#include "CppUnitTest.h"
#include "../../codi/Control/Game.h"	
#include <string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestGame)
{
public:
	TEST_METHOD(test_game)
	{
        string nom = "prova_1";
        Game joc(1, nom);
		Assert::AreEqual(joc.getPuntuacio(), 0);
        Assert::AreEqual(joc.getDificultat(), 1);
        Assert::AreEqual(joc.getNom(), nom);
        Board *tauler = joc.getTauler();
        Assert::AreEqual(tauler->getAltura(), 6);
        Assert::AreEqual(tauler->getAmplada(), 6);
        Assert::AreEqual(tauler->getMines(), 7);

        Game joc2(2, nom);
		Assert::AreEqual(joc2.getPuntuacio(), 0);
        Assert::AreEqual(joc2.getDificultat(), 2);
        Assert::AreEqual(joc2.getNom(), nom);
        tauler = joc2.getTauler();
        Assert::AreEqual(tauler->getAltura(), 8);
        Assert::AreEqual(tauler->getAmplada(), 8);
        Assert::AreEqual(tauler->getMines(), 10);

        Game joc3(3, nom);
		Assert::AreEqual(joc3.getPuntuacio(), 0);
        Assert::AreEqual(joc3.getDificultat(), 3);
        Assert::AreEqual(joc3.getNom(), nom);
        tauler = joc3.getTauler();
        Assert::AreEqual(tauler->getAltura(), 15);
        Assert::AreEqual(tauler->getAmplada(), 15);
        Assert::AreEqual(tauler->getMines(), 35);

        Game joc4(4, nom);
		Assert::AreEqual(joc4.getPuntuacio(), 0);
        Assert::AreEqual(joc4.getDificultat(), 1);
        Assert::AreEqual(joc4.getNom(), nom);
       tauler = joc4.getTauler();
        Assert::AreEqual(tauler->getAltura(), 6);
        Assert::AreEqual(tauler->getAmplada(), 6);
        Assert::AreEqual(tauler->getMines(), 7);
	}
    TEST_METHOD(test_printMatriu)
    {
        vector<vector<Cell>> matriu = {
			{Cell(1, 0, 0, 0), Cell(0, 0, 1, 1), Cell(0, 1, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)},
			{Cell(0, 1, 0, 3), Cell(0, 0, 0, 3), Cell(0, 1, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)},
			{Cell(1, 1, 0, 0), Cell(1, 0, 1, 0), Cell(0, 0, 1, 2), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)},
            {Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)},
            {Cell(1, 0, 0, 0), Cell(0, 0, 0, 4), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)},
            {Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)}
		};

        Game partida(1, "nom");
        Board* tauler = partida.getTauler();
        tauler->setMatriu(matriu);
        vector<vector<char>> matriu_partida = partida.printMatriu();

        vector<vector<char>> matriu_esperada = {
            {' ', 'F', '0', ' ', ' ', ' '},
            {'3', ' ', '1', ' ', ' ', ' '},
            {'X', 'F', 'F', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' '}
        };

        for (int i=0; i < matriu_esperada.size(); i++){
            for (int j=0; j < matriu_esperada[i].size(); j++){
                wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
				Assert::AreEqual(matriu_esperada[i][j], matriu_partida[i][j], message.c_str());
            }
        }
    }
    TEST_METHOD(test_play)
    {

    }
};