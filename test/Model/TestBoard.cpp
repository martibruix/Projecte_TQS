#include "CppUnitTest.h"
#include "../../codi/Model/Board.h"	
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestBoard)
{
public:
	TEST_METHOD(test_getAltura)
	{
		Board tauler(8,6,5);
		Assert::AreEqual(tauler.getAltura(), 8);
	}
	TEST_METHOD(test_getAmplada)
	{
		Board tauler(8,7,5);
		Assert::AreEqual(tauler.getAmplada(), 7);
	}
	TEST_METHOD(test_getMatriu)
	{
		Board tauler(8,7,7);
		vector<vector <Cell>> matriu = tauler.getMatriu();
		Assert::AreEqual(int(matriu.size()), 8);
		Assert::AreEqual(int(matriu[0].size()), 7);
	}
	TEST_METHOD(test_getMines)
	{
		Board tauler(8,10,7);
		Assert::AreEqual(tauler.getMines(), 7);
	}
	TEST_METHOD(test_getFlags)
	{
		Board tauler(10,8,8);
		Assert::AreEqual(tauler.getFlags(), 8);
	}
	TEST_METHOD(test_constructorBoard)
	{
		Board tauler1(-5, 5, 5);
		Assert::IsTrue(tauler1.getAltura() > 0);

		Board tauler2(5, -5, 5);
		Assert::IsTrue(tauler2.getAmplada() > 0);

		Board tauler3(5, 5, -5);
		Assert::IsTrue(tauler3.getMines() > 0);

		Board tauler4(5, 5, 30);
		Assert::IsTrue(tauler4.getMines() <= tauler4.getAmplada() * tauler4.getAltura());
	}
	TEST_METHOD(test_crearMines)
	{
		Board tauler(8, 8, 8);
		tauler.crearMines();
		vector<vector<Cell>> matriu = tauler.getMatriu();
		int num_mines = 0;
		for (int i = 0; i < matriu.size(); i++)
			for (int j = 0; j < matriu[i].size(); j++)
				if (matriu[i][j].esMina())
					num_mines++;
		Assert::AreEqual(num_mines, 8);
	}
	TEST_METHOD(test_setMatriu)
	{
		vector<vector<Cell>> matriu = {
			{Cell(1, 0, 0, 0), Cell(0, 0, 0, 5), Cell(0, 1, 0, 0)},
			{Cell(0, 0, 0, 3), Cell(0, 0, 1, 0), Cell(0, 1, 0, 7)},
			{Cell(1, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 0)}
		};

		Board tauler(3, 3, 3);
		int error = tauler.setMatriu(matriu);
		Assert::AreEqual(error, 0);
		vector<vector<Cell>> matriu_board = tauler.getMatriu();
		for (int i = 0; i < matriu.size(); i++) {
			for (int j = 0; j < matriu[i].size(); j++) {
				Assert::AreEqual(matriu_board[i][j].esMina(), matriu[i][j].esMina());
				Assert::AreEqual(matriu_board[i][j].estaOberta(), matriu[i][j].estaOberta());
				Assert::AreEqual(matriu_board[i][j].teFlag(), matriu[i][j].teFlag());
				Assert::AreEqual(matriu_board[i][j].getSubjacents(), matriu[i][j].getSubjacents());
			}
		}

		Board tauler2(2, 2, 3);
		error = tauler2.setMatriu(matriu);
		Assert::AreEqual(error, -1);

		Board tauler3(4, 4, 3);
		error = tauler3.setMatriu(matriu);
		Assert::AreEqual(error, -1);
	}
	TEST_METHOD(test_calculSubjacents)
	{
		vector<vector<Cell>> matriu = {
			{Cell(0, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0)},
			{Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 0, 0, 0), Cell(1, 0, 0, 0)},
			{Cell(0, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0)},
			{Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)},
			{Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)},
			{Cell(0, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)}
		};
		vector<vector<Cell>> matriu_esperada = {
			{Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0)},
			{Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 5), Cell(1, 0, 0, 0), Cell(0, 0, 0, 8), Cell(1, 0, 0, 0)},
			{Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0)},
			{Cell(0, 0, 0, 3), Cell(0, 0, 0, 4), Cell(0, 0, 0, 4), Cell(0, 0, 0, 3), Cell(0, 0, 0, 3), Cell(0, 0, 0, 2)},
			{Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)},
			{Cell(0, 0, 0, 3), Cell(1, 0, 0, 0), Cell(0, 0, 0, 3), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0)}
		};

		Board tauler(6, 6, 14);
		tauler.setMatriu(matriu);
		tauler.calculSubjacents();
		vector<vector<Cell>> matriu_board = tauler.getMatriu();
		for (int i = 0; i < matriu_esperada.size(); i++)
			for (int j = 0; j < matriu_esperada[i].size(); j++) {
				wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
				Assert::AreEqual(matriu_esperada[i][j].getSubjacents(), matriu_board[i][j].getSubjacents(), message.c_str());
			}
	}
	TEST_METHOD(test_posarFlags)
	{
		// cas bàsic
		Board tauler(8, 8, 8);
		int error = tauler.posarFlags(3, 5);
		Assert::AreEqual(error, 0);
		vector<vector<Cell>> matriu = tauler.getMatriu();
		Assert::AreEqual(matriu[3][5].teFlag(), true);
		Assert::AreEqual(tauler.getFlags(), 7);

		// valors límit/frontera d'altura
		Board tauler2(8, 8, 8);
		error = tauler2.posarFlags(-1, 5);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler2.getFlags(), 8);

		Board tauler3(8, 8, 8);
		error = tauler3.posarFlags(0, 5);
		Assert::AreEqual(error, 0);
		matriu = tauler3.getMatriu();
		Assert::AreEqual(matriu[0][5].teFlag(), true);
		Assert::AreEqual(tauler3.getFlags(), 7);

		Board tauler4(8, 8, 8);
		error = tauler4.posarFlags(1, 5);
		Assert::AreEqual(error, 0);
		matriu = tauler4.getMatriu();
		Assert::AreEqual(matriu[1][5].teFlag(), true);
		Assert::AreEqual(tauler4.getFlags(), 7);

		Board tauler5(8, 8, 8);
		error = tauler5.posarFlags(6, 5);
		Assert::AreEqual(error, 0);
		matriu = tauler5.getMatriu();
		Assert::AreEqual(matriu[6][5].teFlag(), true);
		Assert::AreEqual(tauler5.getFlags(), 7);

		Board tauler6(8, 8, 8);
		error = tauler6.posarFlags(7, 5);
		Assert::AreEqual(error, 0);
		matriu = tauler6.getMatriu();
		Assert::AreEqual(matriu[7][5].teFlag(), true);
		Assert::AreEqual(tauler6.getFlags(), 7);

		Board tauler7(8, 8, 8);
		error = tauler.posarFlags(8, 5);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler7.getFlags(), 8);

		// valors límit/frontera d'amplada
		Board tauler8(8, 8, 8);
		error = tauler8.posarFlags(3, -1);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler8.getFlags(), 8);

		Board tauler9(8, 8, 8);
		error = tauler9.posarFlags(3, 0);
		Assert::AreEqual(error, 0);
		matriu = tauler9.getMatriu();
		Assert::AreEqual(matriu[3][0].teFlag(), true);
		Assert::AreEqual(tauler9.getFlags(), 7);

		Board tauler10(8, 8, 8);
		error = tauler10.posarFlags(3, 1);
		Assert::AreEqual(error, 0);
		matriu = tauler10.getMatriu();
		Assert::AreEqual(matriu[3][1].teFlag(), true);
		Assert::AreEqual(tauler10.getFlags(), 7);

		Board tauler11(8, 8, 8);
		error = tauler11.posarFlags(3, 6);
		Assert::AreEqual(error, 0);
		matriu = tauler11.getMatriu();
		Assert::AreEqual(matriu[3][6].teFlag(), true);
		Assert::AreEqual(tauler11.getFlags(), 7);

		Board tauler12(8, 8, 8);
		error = tauler12.posarFlags(3, 7);
		Assert::AreEqual(error, 0);
		matriu = tauler12.getMatriu();
		Assert::AreEqual(matriu[3][7].teFlag(), true);
		Assert::AreEqual(tauler12.getFlags(), 7);

		Board tauler13(8, 8, 8);
		error = tauler13.posarFlags(3, 8);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler13.getFlags(), 8);

		// casos alternatius
		Board tauler14(3, 3, 1);
		tauler14.posarFlags(0, 0);
		error = tauler14.posarFlags(0, 1);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler14.getFlags(), 0);

		Board tauler15(3, 3, 3);
		tauler15.posarFlags(0, 0);
		error = tauler15.posarFlags(0, 0);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler15.getFlags(), 2);

		Board tauler16(3, 3, 3);
		tauler16.obrirCasella(0, 0);
		error = tauler16.posarFlags(0, 0);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler16.getFlags(), 3);

	}
	TEST_METHOD(test_treureFlags)
	{
		// cas bàsic
		Board tauler(8, 8, 8);
		tauler.posarFlags(3, 5);
		int error = tauler.treureFlags(3, 5);
		Assert::AreEqual(error, 0);
		vector<vector<Cell>> matriu = tauler.getMatriu();
		Assert::AreEqual(matriu[3][5].teFlag(), false);
		Assert::AreEqual(tauler.getFlags(), 8);

		// valors límit/frontera d'altura
		Board tauler2(8, 8, 8);
		tauler2.posarFlags(-1, 5);
		error = tauler2.treureFlags(-1, 5);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler2.getFlags(), 8);

		Board tauler3(8, 8, 8);
		tauler3.posarFlags(0, 5);
		error = tauler3.treureFlags(0, 5);
		Assert::AreEqual(error, 0);
		matriu = tauler3.getMatriu();
		Assert::AreEqual(matriu[0][5].teFlag(), false);
		Assert::AreEqual(tauler3.getFlags(), 8);

		Board tauler4(8, 8, 8);
		tauler4.posarFlags(1, 5);
		error = tauler4.treureFlags(1, 5);
		Assert::AreEqual(error, 0);
		matriu = tauler4.getMatriu();
		Assert::AreEqual(matriu[1][5].teFlag(), false);
		Assert::AreEqual(tauler4.getFlags(), 8);

		Board tauler5(8, 8, 8);
		tauler5.posarFlags(6, 5);
		error = tauler5.treureFlags(6, 5);
		Assert::AreEqual(error, 0);
		matriu = tauler5.getMatriu();
		Assert::AreEqual(matriu[6][5].teFlag(), false);
		Assert::AreEqual(tauler5.getFlags(), 8);

		Board tauler6(8, 8, 8);
		tauler6.posarFlags(7, 5);
		error = tauler6.treureFlags(7, 5);
		Assert::AreEqual(error, 0);
		matriu = tauler6.getMatriu();
		Assert::AreEqual(matriu[7][5].teFlag(), false);
		Assert::AreEqual(tauler6.getFlags(), 8);

		Board tauler7(8, 8, 8);
		tauler.posarFlags(8, 5);
		error = tauler.treureFlags(8, 5);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler7.getFlags(), 8);

		// valors límit/frontera d'amplada
		Board tauler8(8, 8, 8);
		tauler8.posarFlags(3, -1);
		error = tauler8.treureFlags(3, -1);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler8.getFlags(), 8);

		Board tauler9(8, 8, 8);
		tauler9.posarFlags(3, 0);
		error = tauler9.treureFlags(3, 0);
		Assert::AreEqual(error, 0);
		matriu = tauler9.getMatriu();
		Assert::AreEqual(matriu[3][0].teFlag(), false);
		Assert::AreEqual(tauler9.getFlags(), 8);

		Board tauler10(8, 8, 8);
		tauler10.posarFlags(3, 1);
		error = tauler10.treureFlags(3, 1);
		Assert::AreEqual(error, 0);
		matriu = tauler10.getMatriu();
		Assert::AreEqual(matriu[3][1].teFlag(), false);
		Assert::AreEqual(tauler10.getFlags(), 8);

		Board tauler11(8, 8, 8);
		tauler11.posarFlags(3, 6);
		error = tauler11.treureFlags(3, 6);
		Assert::AreEqual(error, 0);
		matriu = tauler11.getMatriu();
		Assert::AreEqual(matriu[3][6].teFlag(), false);
		Assert::AreEqual(tauler11.getFlags(), 8);

		Board tauler12(8, 8, 8);
		tauler12.posarFlags(3, 7);
		error = tauler12.treureFlags(3, 7);
		Assert::AreEqual(error, 0);
		matriu = tauler12.getMatriu();
		Assert::AreEqual(matriu[3][7].teFlag(), false);
		Assert::AreEqual(tauler12.getFlags(), 8);

		Board tauler13(8, 8, 8);
		tauler13.posarFlags(3, 8);
		error = tauler13.treureFlags(3, 8);
		Assert::AreEqual(error, -1);
		Assert::AreEqual(tauler13.getFlags(), 8);

		// casos alternatius
		Board tauler14(8, 8, 8);
		tauler14.posarFlags(3, 5);
		error = tauler14.treureFlags(4, 5);
		Assert::AreEqual(error, -1);
		matriu = tauler14.getMatriu();
		Assert::AreEqual(matriu[4][5].teFlag(), false);
		Assert::AreEqual(tauler14.getFlags(), 7);
	}
	TEST_METHOD(test_obrirCasella)
	{
		vector<vector<Cell>> matriu = {
			{Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
			{Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0)},
			{Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 3), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0)}
		};

		Board tauler(8, 8, 10);
		tauler.setMatriu(matriu);

		// obrir una casella sense mina i sense recursivitat
		vector<vector<Cell>> matriu_esperada = {
			{Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 1, 0, 1), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
			{Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0)},
			{Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(0, 0, 0, 2), Cell(0, 0, 0, 3), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0), Cell(0, 0, 0, 1), Cell(1, 0, 0, 0)}
		};
		int puntuacio = tauler.obrirCasella(0, 5);
		Assert::AreEqual(puntuacio, 10);
		vector<vector<Cell>> matriu_board = tauler.getMatriu();
		for (int i = 0; i < matriu_esperada.size(); i++)
			for (int j = 0; j < matriu_esperada[i].size(); j++) {
				wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
				Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
			}

		// obrir una casella sense mina i amb recursivitat
		matriu_esperada = {
			{Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 1, 0, 1), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
			{Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(0, 0, 0, 1)},
			{Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 0)},
			{Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 0, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(0, 1, 0, 2), Cell(0, 1, 0, 3), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0)}
		};
		puntuacio = tauler.obrirCasella(4, 3);
		Assert::AreEqual(puntuacio, 370);
		matriu_board = tauler.getMatriu();
		for (int i = 0; i < matriu_esperada.size(); i++)
			for (int j = 0; j < matriu_esperada[i].size(); j++) {
				wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
				Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
			}

		// obrir una casella sense mina i amb recursivitat
		matriu_esperada = {
			{Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 1, 0, 1), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
			{Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1)},
			{Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0)},
			{Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1)},
			{Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(0, 1, 0, 2), Cell(0, 1, 0, 3), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0)}
		};
		puntuacio = tauler.obrirCasella(2, 7);
		Assert::AreEqual(puntuacio, 60);
		matriu_board = tauler.getMatriu();
		for (int i = 0; i < matriu_esperada.size(); i++)
			for (int j = 0; j < matriu_esperada[i].size(); j++) {
				wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
				Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
			}

		// obrir una casella amb mina
		matriu_esperada = {
			{Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(0, 0, 0, 2), Cell(0, 1, 0, 1), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0)},
			{Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 2), Cell(1, 0, 0, 0), Cell(0, 0, 0, 2), Cell(1, 0, 0, 0), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1)},
			{Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0)},
			{Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1)},
			{Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(0, 1, 0, 2), Cell(0, 1, 0, 3), Cell(0, 1, 0, 2), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(0, 0, 0, 1)},
			{Cell(0, 0, 0, 1), Cell(1, 1, 0, 0), Cell(1, 0, 0, 0), Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0), Cell(0, 1, 0, 1), Cell(1, 0, 0, 0)}
		};
		puntuacio = tauler.obrirCasella(7, 1);
		Assert::AreEqual(puntuacio, -1);
		matriu_board = tauler.getMatriu();
		for (int i = 0; i < matriu_esperada.size(); i++)
			for (int j = 0; j < matriu_esperada[i].size(); j++) {
				wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
				Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
			}

		// obrir una casella que ja estava oberta
		puntuacio = tauler.obrirCasella(4, 4);
		Assert::AreEqual(puntuacio, -2);
		matriu_board = tauler.getMatriu();
		for (int i = 0; i < matriu_esperada.size(); i++)
			for (int j = 0; j < matriu_esperada[i].size(); j++) {
				wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
				Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
			}

		// obrir una casella on hi ha un flag
		tauler.posarFlags(7, 3);
		puntuacio = tauler.obrirCasella(7, 3);
		Assert::AreEqual(puntuacio, -2);
		matriu_board = tauler.getMatriu();
		for (int i = 0; i < matriu_esperada.size(); i++)
			for (int j = 0; j < matriu_esperada[i].size(); j++) {
				wstring message = L"Error a la posició (" + to_wstring(i) + L", " + to_wstring(j) + L")";
				Assert::AreEqual(matriu_esperada[i][j].estaOberta(), matriu_board[i][j].estaOberta(), message.c_str());
			}
	}
	TEST_METHOD(test_victoria)
	{
		vector<vector<Cell>> matriu = {
			{Cell(1, 0, 0, 0), Cell(0, 0, 0, 1), Cell(0, 1, 0, 0)},
			{Cell(0, 1, 0, 3), Cell(0, 1, 0, 3), Cell(0, 1, 0, 1)},
			{Cell(1, 0, 0, 0), Cell(1, 0, 1, 0), Cell(0, 0, 0, 1)}
		};

		Board tauler(3, 3, 3);
		tauler.setMatriu(matriu);
		int win = tauler.victoria();
		Assert::AreEqual(win, 0);

		matriu = {
			{Cell(1, 0, 0, 0), Cell(0, 1, 0, 1), Cell(0, 1, 0, 0)},
			{Cell(0, 1, 0, 3), Cell(0, 1, 0, 3), Cell(0, 1, 0, 1)},
			{Cell(1, 0, 0, 0), Cell(1, 0, 1, 0), Cell(0, 1, 0, 1)}
		};

		Board tauler2(3, 3, 3);
		tauler2.setMatriu(matriu);
		win = tauler2.victoria();
		Assert::AreEqual(win, 1);
	}
};