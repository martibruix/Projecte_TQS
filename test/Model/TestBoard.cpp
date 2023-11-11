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
};