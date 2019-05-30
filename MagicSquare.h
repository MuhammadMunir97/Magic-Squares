#pragma once
#include <iostream>
#include <vector>

using namespace std;

class MagicSquare
{
private:
	unsigned int SquareSize;
	vector<vector<int>> Square;
	unsigned int MagicSum;
public:
	void  MagicSquare::ReadInSquare(ifstream &file,unsigned int Size);
	void  MagicSquare::DisplaySquare();
	bool  MagicSquare::IsSquareMagic();
	bool  MagicSquare::CheckSquareErrors();
};
