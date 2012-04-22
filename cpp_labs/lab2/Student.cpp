// Include our student outline
#include "Student.h"

// Default constructor, nothing here...
Student::Student()
{ }

// Constructor with one string
Student::Student(string _name)
{
	name = _name;
}

// Constructor with one string and an int
Student::Student(string _name, int _age)
{
	name = _name;
	age = _age;
}

// Constructor with two strings and an int
Student::Student(string _name, int _age, string _school)
{
	name = _name;
	age = _age;
	school = _school;
}

void Student::print() {
	
	// We can use cout because Student.h includes <iostream>
	if (school != "")
	{
		cout << name << " is attending " << school << endl;
	} else { 
		cout << name << " is not attending school, what a bum!" << endl;
	}
	
}
