#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "word.h"

using namespace std;

const int MAX = 100;

int main ()
{
	//Open file for input
	ifstream input("words.txt");
	string inword;
	Word words[MAX];
	//Initialize word counter
	int count = 0;
	//Read until array is filled or EOF is found
	while (count < MAX && input >> inword)
	{
		//Insert word into array
		words[count].setWord(inword);
		//Increment counter
		count++;
	}
//Close input file
input.close();
//Print report header
/*cout << setw (12) << left << "Word";
cout << setw(8) << right << "Vowels";
cout << setw(8) << right << "Const.";
cout << setw (8) << right << "Digits";
cout << setw (8) << right << "Special";
cout << endl;*/

//Print to output
ofstream output("output.txt");
output << setw (12) << left << "Word";
output << setw(8) << right << "Vowels";
output << setw(8) << right << "Const.";
output << setw (8) << right << "Digits";
output << setw (8) << right << "Special";
output << endl;

//Loop through all words in array
for (int i = 0; i < count; i++)
{
	//Print data for word
	//words[i].write(cout);
	words[i].write(output);
	output << endl;
}
return 0;
}
