#pragma once

using namespace std;

class Cell
{
public:
	Cell() { mina = false; oberta = false; flag = false; subjacents = 0; };
private:
	bool mina, oberta, flag;
	int subjacents;
};