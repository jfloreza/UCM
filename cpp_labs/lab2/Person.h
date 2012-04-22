// Person.h -- the generic person class

// These two lines tell the preprocessor that if the 
// constant _PERSON_H_ is not already defined, then we 
// want to define it, and the person class. Otherwise 
// if it's arleady defined, the pre-processor skips 
// the contents of this file. This prevents our .h file
// from having its contents included twice in our program
// which would lead to errors

#ifndef _PERSON_H_
#define _PERSON_H_

// cin, cout, string, etc. exist in this namespace
using namespace std; 

#include <string>
#include <iostream>

class Person { 
	
	protected:
		string name; 
		int age; 
		char gender; 
	
	public:
		Person(); 
		Person(string _name);
		Person(string _name, int _age);
		
		void print();
};

#endif

