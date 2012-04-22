#ifndef _WORD_H_
#define _WORD_H_

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class Word
{
	public:
		Word();
		~Word();
		void setWord(const string input);
		void write(ostream &outstream) const;

	private:
	string word;
	int vowels;
	int consonants;
	int digits;
	int specialchars;
};


#endif

Word::Word() {
	word = "NULL";
	vowels = 0;
	consonants = 0;
	digits = 0;
	specialchars = 0;
}

Word::~Word() {
	cout << "Object destroyed" << endl;
	cout << word << endl;
}

void Word::setWord(const string input){
	word = input;
	string s = word;
	char c;
	for (int i = 0; i < s.size(); i++)
	{
		c = s[i];
		c = tolower(c);
		if (isdigit(c))digits++;
		else if (isalpha(c) && c == 'o'||c=='a'||c=='e'||c=='i'||c=='u')vowels++;
		else if ( !isdigit(c) && !isalpha(c) )specialchars++;
		else consonants++;
		
		
	}
}

void Word::write(ostream &outstream) const{

/*cout << setw (12) << left << word;
cout << setw(8) << right << vowels;
cout << setw(8) << right << consonants;
cout << setw (8) << right << digits;
cout << setw (8) << right << specialchars;
cout << endl;*/

outstream << setw (12) << left << word;
outstream << setw(8) << right << vowels;
outstream << setw(8) << right << consonants;
outstream << setw (8) << right << digits;
outstream << setw (8) << right << specialchars;
outstream << endl;

}

