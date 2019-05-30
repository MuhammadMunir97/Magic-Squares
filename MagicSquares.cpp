#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include "MagicSquare.h"

void  MagicSquare::ReadInSquare(ifstream &file,unsigned int Size)
{
	Square.clear();
	SquareSize = Size;
	int t = 0;

	for (unsigned int row = 0;row < SquareSize;row++)
	{
		vector<int> temp;
		for (unsigned int col = 0;col < SquareSize;col++)
		{
			file >> t;
			temp.push_back(t);
			}
		Square.push_back(temp);
	}
	DisplaySquare();
}

void  MagicSquare::DisplaySquare()
{
	for (unsigned int Row = 0; Row < Square.size();Row++)
	{
		cout << endl;
		for (unsigned int Col = 0; Col < Square.size();Col++)
		{
			cout << setw(4) << Square[Row][Col] ;
		}
		cout << endl;
	}
	bool b2;
	b2 = CheckSquareErrors();

	if (b2 == false)
	{
		cout << "The matrix is not a proper square. pls check the input file" << endl;
	}

	bool b1;
	b1 = IsSquareMagic();

	if (b1 == true)
	{
		cout << "A " << SquareSize << " Magic Square with a magic sum of " << MagicSum << endl;
	}
	else
	{
		cout << "The given Matrix was not a magic square" << endl;
	}

}

bool MagicSquare::IsSquareMagic()
{
	MagicSum = ((SquareSize*((SquareSize*SquareSize) + 1)) / 2);
	unsigned int SumRows = 0;
	unsigned int SumCols = 0;

	for (unsigned int Row = 0;Row < SquareSize;Row++)
	{
		SumRows = 0;
		SumCols = 0;
		for (unsigned int Col = 0;Col < SquareSize;Col++)
		{
			SumRows += Square[Row][Col];
			SumCols += Square[Col][Row];
		}
		if ((SumRows != MagicSum) || (SumCols != MagicSum))
		{
			return false;
		}
	}

	unsigned int Diagonala = 0;
	unsigned int Diagonalb = 0;

	unsigned int Col = (SquareSize - 1);

	for (unsigned int Row = 0;Row < SquareSize;Row++)
	{
		Diagonala += Square[Row][Row];
		Diagonalb += Square[Row][Col--];
	}

	
	if ((Diagonala != MagicSum) || (Diagonalb != MagicSum))
	{
		return false;
	}

	return true;
}

 
bool  MagicSquare::CheckSquareErrors()
{
	unsigned int check = 0;

	check = ((SquareSize*SquareSize) + 1);

	unsigned int count = 0;

	// The error variable will check to see if the number within the given range
	// is in the vector or not
	// if it is then we would get a 1 
	// if it does not exist we woud get a 0
	// if it exists more then once then we would get a number greater then 1
	// if the number is not 1 this would return an error
	unsigned int error = 0;
	for (count = 1;count < check;count++)
	{
		for (unsigned int Row = 0; Row < Square.size();Row++)
		{
			for (unsigned int Col = 0; Col < Square.size();Col++)
			{
				if (count == Square[Row][Col])
				{
					error++;
			    }
			}
		}
		if (error != 1)
		{
			return false;
		}
		error = 0;
	}

	return true;
}