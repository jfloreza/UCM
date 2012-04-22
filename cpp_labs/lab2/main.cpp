#include "Person.h"
#include "Student.h"
#include "Doctor.h"

using namespace std; 

int main(int argc, char *argv[])
{
	
	Person *p = new Person("Bob Smith", 19);
	Person *p2 = new Person("John Smith", 21);
	Person *p3 = new Person("Agent Smith", 00);
	//Student *s = new Student("Sally Smith", 21, "UCM");
	//Student *s1 = new Student("Bill Joy", 42);
		
	Doctor *d = new Doctor("Johnny Jay", "UCM Dentistry");
	d->addPatient(p);
	d->addPatient(p2);
	d->addPatient(p3);
	
	//s->print();
	//s1->print();
	//p->print();
	d->print();
	
	//((Person *)s)->print();
	
	// Return 0 implies all went well
	return 0;
	
}
