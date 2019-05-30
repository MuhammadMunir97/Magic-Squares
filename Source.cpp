//Create a class that holds the matrice
//read the matrice from a .txt file
//Check if the matrice is or is not a magic square 
//Output the answer

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "MagicSquare.h"
using namespace std;

int main()
{
	ifstream inData;
	inData.open("MagicText1.txt");
	if (!inData)
	{
		cout << "The input file does not exist. Program terminates!"
			<< endl;
		return 1;
	}
	unsigned int Size;
	do {
		Size = 0;
		// The program will end when their are no more squares
		// The program can end two ways
		// either through exit(0)
		// or by the loop ending
		inData >> Size;
		if (Size == 0)
		{
			cout << "No more matrices " << endl;
			cout << "Press a key to end program " << endl;
			getchar();
			exit(0);
		}
		else
		{
			MagicSquare y;
			y.ReadInSquare(inData, Size);
		}
		cout << "Press a key to see the next matrix " << endl;
		getchar();
	} while (Size != 0);

}
// Read square Size in main