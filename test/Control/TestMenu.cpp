#include "CppUnitTest.h"
#include <fstream>
#include <sstream>
#include <cstdio>
#include "../../codi/Control/Menu.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestMenu)
{
public:
	TEST_METHOD(test_guardarPuntuacio)
	{
		string path = "../../files/RankingTest.txt";
		ofstream file;
		file.open(path);
		
		Menu menu;
		string nom, resultat, puntuacio, dificultat;
		
		menu.guardarPuntuacio("nom1", 1, 290, 1, path);
		file.close();
		string linea;
		ifstream file2(path);
		getline(file2, linea);
		stringstream input_stringstream(linea);
		getline(input_stringstream, nom, ' ');
		getline(input_stringstream, resultat, ' ');
		getline(input_stringstream, puntuacio, ' ');
		getline(input_stringstream, dificultat, ' ');
		file2.close();
		Assert::AreEqual(string("nom1"), nom);
		Assert::AreEqual(string("1"), resultat);
		Assert::AreEqual(string("290"), puntuacio);
		Assert::AreEqual(string("1"), dificultat);

		menu.guardarPuntuacio("nom2", 0, 150, 2, path);
		file2.open(path);
		getline(file2, linea);
		stringstream input_stringstream2(linea);
		getline(input_stringstream2, nom, ' ');
		getline(input_stringstream2, resultat, ' ');
		getline(input_stringstream2, puntuacio, ' ');
		getline(input_stringstream2, dificultat, ' ');
		Assert::AreEqual(string("nom1"), nom);
		Assert::AreEqual(string("1"), resultat);
		Assert::AreEqual(string("290"), puntuacio);
		Assert::AreEqual(string("1"), dificultat);
		getline(file2, linea);
		stringstream input_stringstream3(linea);
		getline(input_stringstream3, nom, ' ');
		getline(input_stringstream3, resultat, ' ');
		getline(input_stringstream3, puntuacio, ' ');
		getline(input_stringstream3, dificultat, ' ');
		Assert::AreEqual(string("nom2"), nom);
		Assert::AreEqual(string("0"), resultat);
		Assert::AreEqual(string("150"), puntuacio);
		Assert::AreEqual(string("2"), dificultat);
		file2.close();

		remove(path.c_str());
	}
	TEST_METHOD(test_llegirRanking)
	{
		string path = "../../files/RankingTest.txt";
		ofstream file;
		file.open(path);

		Menu menu;
		menu.guardarPuntuacio("nom1", 1, 290, 1, path);
		menu.guardarPuntuacio("nom2", 0, 90, 2, path);
		menu.guardarPuntuacio("nom3", 0, 30, 3, path);
		vector<vector<string>> ranking = menu.llegirRanking(path);

		Assert::AreEqual(string("nom1"), ranking[0][0]);
		Assert::AreEqual(string("1"), ranking[0][1]);
		Assert::AreEqual(string("290"), ranking[0][2]);
		Assert::AreEqual(string("1"), ranking[0][3]);
		Assert::AreEqual(string("nom2"), ranking[1][0]);
		Assert::AreEqual(string("0"), ranking[1][1]);
		Assert::AreEqual(string("90"), ranking[1][2]);
		Assert::AreEqual(string("2"), ranking[1][3]);
		Assert::AreEqual(string("nom3"), ranking[2][0]);
		Assert::AreEqual(string("0"), ranking[2][1]);
		Assert::AreEqual(string("30"), ranking[2][2]);
		Assert::AreEqual(string("3"), ranking[2][3]);
		file.close();
		remove(path.c_str());
	}
};