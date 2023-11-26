#include "CppUnitTest.h"
#include "../../codi/Control/Game.h"	
#include "MockInputGame.h"
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
    TEST_METHOD(test_getCharMatriu)
    {
        Game partida(1, "nom");

        char a = partida.getCharMatriu(false, false, true, 2);
        Assert::AreEqual('F', a);

        a = partida.getCharMatriu(false, true, false, 0);
        Assert::AreEqual('0', a);
        
        a = partida.getCharMatriu(true, false, false, 2);
        Assert::AreEqual('E', a);

        a = partida.getCharMatriu(true, true, true, -1);
        Assert::AreEqual('E', a);

        a = partida.getCharMatriu(false, false, false, -1);
        Assert::AreEqual('E', a);
        
        a = partida.getCharMatriu(true, true, false, 0);
        Assert::AreEqual('X', a);
        
        a = partida.getCharMatriu(true, false, true, 0);
        Assert::AreEqual('F', a);
        
        a = partida.getCharMatriu(true, true, false, 2);
        Assert::AreEqual('E', a);
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
        vector<vector<Cell>> matriu = {
            {Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0)},
            {Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
            {Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 3), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)}
        };

        // Obrir mina i perdre
        //vector<string> instruccions = {"OPEN 0 0"};
        vector<vector<int>> instruccions = { {0, 0, 0} };
        MockInputGame mockInput(instruccions);
        Game partida(1, "nom", mockInput);
        Board* tauler = partida.getTauler();
        tauler->setMatriu(matriu);

        int result = partida.play();
        Assert::AreEqual(0, result);
        int puntuacio = partida.getPuntuacio();
        Assert::AreEqual(0, puntuacio);
        vector<vector<Cell>> matriu_esperada = {
            {Cell(1, 1, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0)},
            {Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
            {Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 3), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)}
        };
        vector<vector<Cell>> matriu_board = tauler->getMatriu();
        for (int i = 0; i < matriu_esperada.size(); i++) {
            for (int j = 0; j < matriu_esperada[i].size(); j++) {
                wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
                Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
                Assert::AreEqual(matriu_esperada[i][j].teFlag(), matriu_board[i][j].teFlag(), message.c_str());
            }
        }

        // Obrir 3 caselles i sortir
        //instruccions = { "OPEN 1 0", "OPEN 1 1", "OPEN 1 2", "EXIT"};
        instruccions = { {0, 1, 0}, {0, 1, 1}, {0, 1, 2}, {3} };
        MockInputGame mockInput2(instruccions);
        Game partida2(1, "nom", mockInput2);
        tauler = partida2.getTauler();
        tauler->setMatriu(matriu);

        result = partida2.play();
        Assert::AreEqual(-1, result);
        puntuacio = partida2.getPuntuacio();
        Assert::AreEqual(30, puntuacio);
        matriu_esperada = {
            {Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0)},
            {Cell(0, 1, 0, 2), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
            {Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 3), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)}
        };
        matriu_board = tauler->getMatriu();
        for (int i = 0; i < matriu_esperada.size(); i++) {
            for (int j = 0; j < matriu_esperada[i].size(); j++) {
                wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
                Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
                Assert::AreEqual(matriu_esperada[i][j].teFlag(), matriu_board[i][j].teFlag(), message.c_str());
            }
        }
        
        // Obrir totes les caselles i guanyar
        //instruccions = { "OPEN 0 1", "OPEN 0 2", "OPEN 0 3", "OPEN 0 4", "OPEN 1 0", "OPEN 1 1", "OPEN 1 2",
        //    "OPEN 1 3", "OPEN 1 4", "OPEN 1 5", "OPEN 2 0", "OPEN 2 2", "OPEN 2 3", "OPEN 2 4", "OPEN 2 5",
        //    "OPEN 3 0", "OPEN 3 2", "OPEN 3 4", "OPEN 4 0", "OPEN 4 1", "OPEN 4 2", "OPEN 4 3", "OPEN 4 4",
        //    "OPEN 4 5", "OPEN 5 0", "OPEN 5 1", "OPEN 5 3", "OPEN 5 4", "OPEN 5 5" };
        instruccions = { {0, 0, 1}, {0, 0, 2}, {0, 0, 3}, {0, 0, 4}, {0, 1, 0}, {0, 1, 1}, {0, 1, 2},
            {0, 1, 3}, {0, 1, 4}, {0, 1, 5}, {0, 2, 0}, {0, 2, 2}, {0, 2, 3}, {0, 2, 4}, {0, 2, 5},
            {0, 3, 0}, {0, 3, 2}, {0, 3, 4}, {0, 4, 0}, {0, 4, 1}, {0, 4, 2}, {0, 4, 3}, {0, 4, 4},
            {0, 4, 5}, {0, 5, 0}, {0, 5, 1}, {0, 5, 3}, {0, 5, 4}, {0, 5, 5} };
        MockInputGame mockInput3(instruccions);
        Game partida3(1, "nom", mockInput3);
        tauler = partida3.getTauler();
        tauler->setMatriu(matriu);
        
        result = partida3.play();
        Assert::AreEqual(1, result);
        puntuacio = partida3.getPuntuacio();
        Assert::AreEqual(290, puntuacio);
        matriu_esperada = {
            {Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0)},
            {Cell(0, 1, 0, 2), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1)},
            {Cell(0, 1, 0, 2), Cell(1, 0, 0, 0), Cell(0, 1, 0, 3), Cell(0, 1, 0, 1), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1)},
            {Cell(0, 1, 0, 2), Cell(1, 0, 0, 0), Cell(0, 1, 0, 3), Cell(1, 0, 0, 0), Cell(0, 1, 0, 2), Cell(1, 0, 0, 0)},
            {Cell(0, 1, 0, 1), Cell(0, 1, 0, 2), Cell(0, 1, 0, 3), Cell(0, 1, 0, 2), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1)},
            {Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0)}
        };
        matriu_board = tauler->getMatriu();
        for (int i = 0; i < matriu_esperada.size(); i++) {
            for (int j = 0; j < matriu_esperada[i].size(); j++) {
                wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
                Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
                Assert::AreEqual(matriu_esperada[i][j].teFlag(), matriu_board[i][j].teFlag(), message.c_str());
            }
        }

        // Obrir dos caselles (amb recursivitat i sense) i apretar una mina
        //instruccions = { "OPEN 0 3", "OPEN 5 3", "OPEN 3 1" };
        instruccions = { {0, 0, 3}, {0, 5, 3}, {0, 3, 1} };
        MockInputGame mockInput4(instruccions);
        Game partida4(1, "nom", mockInput4);
        tauler = partida4.getTauler();
        tauler->setMatriu(matriu);
        
        result = partida4.play();
        Assert::AreEqual(0, result);
        puntuacio = partida4.getPuntuacio();
        Assert::AreEqual(120, puntuacio);
        matriu_esperada = {
            {Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0)},
            {Cell(0, 0, 0, 2), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 1, 0, 3), Cell(0, 1, 0, 1), Cell(0, 1, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 1, 0, 0), Cell(0, 0, 0, 3), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
            {Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 3), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)}
        };
        matriu_board = tauler->getMatriu();
        for (int i = 0; i < matriu_esperada.size(); i++) {
            for (int j = 0; j < matriu_esperada[i].size(); j++) {
                wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
                Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
                Assert::AreEqual(matriu_esperada[i][j].teFlag(), matriu_board[i][j].teFlag(), message.c_str());
            }
        }

        // Posar flag, posar flag a la mateixa posicio, provar d'obrir la casella on hi ha flag,
        // posar totes les flags, veure que no es poden posar més, treure flag a posicio incorrecta,
        // treure 2 flags a posicions correctes i marxar
        //instruccions = { "P 0 0", "P 0 0", "OPEN 0 0", "P 0 1", "P 0 2", "P 0 3", "P 0 4", "P 0 5", "P 1 0",
        //    "P 1 1", "T 2 0", "T 0 0", "T 0 1", "EXIT" };
        instruccions = { {1, 0, 0}, {1, 0, 0}, {0, 0, 0}, {1, 0, 1}, {1, 0, 2}, {1, 0, 3}, {1, 0, 4},
            {1, 0, 5}, {1, 1, 0}, {1, 1, 1}, {2, 2, 0}, {2, 0, 0}, {2, 0, 1}, {3} };
        MockInputGame mockInput5(instruccions);
        Game partida5(1, "nom", mockInput5);
        tauler = partida5.getTauler();
        tauler->setMatriu(matriu);
        
        result = partida5.play();
        Assert::AreEqual(-1, result);
        puntuacio = partida5.getPuntuacio();
        Assert::AreEqual(0, puntuacio);
        matriu_esperada = {
            {Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 1, 0), Cell(0, 0, 1, 0), Cell(0, 0, 1, 1), Cell(1, 0, 1, 0)},
            {Cell(0, 0, 1, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
            {Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 3), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)}
        };
        matriu_board = tauler->getMatriu();
        for (int i = 0; i < matriu_esperada.size(); i++) {
            for (int j = 0; j < matriu_esperada[i].size(); j++) {
                wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
                Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
                Assert::AreEqual(matriu_esperada[i][j].teFlag(), matriu_board[i][j].teFlag(), message.c_str());
            }
        }

        // Rebre una instruccio incorrecta, obrir una casella i abandonar la partida
        //instruccions = {"AAA", "OPEN", "OPEN 2", "X 2 3", "P -2 4", "T 1 14", "P 0 1 2", "", "EXIT 2 3", "EXIT"};
        instruccions = { {-1}, {0, 0, 1}, {3} };
        MockInputGame mockInput6(instruccions);
        Game partida6(1, "nom", mockInput6);
        tauler = partida6.getTauler();
        tauler->setMatriu(matriu);
        
        result = partida6.play();
        Assert::AreEqual(-1, result);
        puntuacio = partida6.getPuntuacio();
        Assert::AreEqual(10, puntuacio);
        matriu_esperada = {
            {Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0)},
            {Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
            {Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 3), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
            {Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)}
        };
        matriu_board = tauler->getMatriu();
        for (int i = 0; i < matriu_esperada.size(); i++) {
            for (int j = 0; j < matriu_esperada[i].size(); j++) {
                wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
                Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
                Assert::AreEqual(matriu_esperada[i][j].teFlag(), matriu_board[i][j].teFlag(), message.c_str());
            }
        }
    }
};