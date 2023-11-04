#pragma once

using namespace std;

class Cell
{
public:
	Cell() { mina = false; oberta = false; flag = false; subjacents = 0; };
	Cell(bool min, bool ob, bool fl, int subj) {
		mina = min;
		oberta = ob;
		flag = fl;
		subjacents = subj;
	};

	bool esMina() { return mina; }
	bool estaOberta() { return oberta; }
	bool teFlag() { return flag; }
	int getSubjacents() { return subjacents; }

	void setMina() { mina = true;}
	void setOberta() { oberta = true;}
	void setFlag() { flag = !flag; }
	void setSubjacents(int num_subjacent) { subjacents = num_subjacent; }
private:
	bool mina;
	bool oberta;
	bool flag;
	int subjacents;
};