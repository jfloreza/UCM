// Include doctor outline
#include "Doctor.h"

//Default constructor
Doctor::Doctor()
{ }

//Constructor with one string
Doctor::Doctor(string _name)
{
	name = _name;
}


//Constructor for business
Doctor::Doctor(string _name, string _place)
{
	name = _name;
	place = _place;
}

//Vectors
void Doctor::addPatient(Person *patient)
{
	patients.push_back(patient);
}

void Doctor::print()
{
	int size = patients.size();
	int count = 0;
	cout << "Dr. " <<  name << " works for " << place << "." << endl;
	cout << "His patients are:" << endl;
	
	for (count = 0; count < size; count++)
	{
		patients[count]->print();
	}
	cout << "Number of patients is: " << size << endl;
}
