#ifndef _DOCTOR_H_
#define _DOCTOR_H_

using namespace std;

#include "Person.h"
#include <string>
#include <iostream>
#include <vector>

class Doctor : public Person
{
	protected:
		string place;
		vector<Person *> patients;
		int count;
	
	public:
		Doctor();
		Doctor(string _name);
		Doctor(string _name, string _place);
		
		//Adding patients
		void addPatient(Person *patients);	

		//Print() override
		void print();
};

#endif
