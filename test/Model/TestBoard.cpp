#include "CppUnitTest.h"
#include "../../codi/Model/Board.h"	

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
};