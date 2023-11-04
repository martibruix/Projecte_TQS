#include "CppUnitTest.h"
#include "../../codi/Model/Cell.h"	

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TestCell)
{
public:
	TEST_METHOD(test_cell)
	{
		Cell casella(true, false, true, 3);
		Assert::AreEqual(casella.esMina(), true);
		Assert::AreEqual(casella.estaOberta(), false);
		Assert::AreEqual(casella.teFlag(), true);
		Assert::AreEqual(casella.getSubjacents(), 3);
	}
	TEST_METHOD(test_setMina)
	{
		Cell casella(false, false, false, 0);
		casella.setMina();
		Assert::AreEqual(casella.esMina(), true);
	}
	TEST_METHOD(test_setOberta)
	{
		Cell casella(false, false, false, 0);
		casella.setOberta();
		Assert::AreEqual(casella.estaOberta(), true);
	}
	TEST_METHOD(test_setFlag)
	{
		Cell casella(false, false, true, 3);
		casella.setFlag();
		Assert::AreEqual(casella.teFlag(), false);
		casella.setFlag();
		Assert::AreEqual(casella.teFlag(), true);
	}
	TEST_METHOD(test_setSubjacents)
	{
		Cell casella(false, false, false, 0);
		casella.setSubjacents(5);
		Assert::AreEqual(casella.getSubjacents(), 5);
	}
};