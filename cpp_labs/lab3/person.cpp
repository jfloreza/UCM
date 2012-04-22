#include "person.h"

Person::Person() {
}

Person::Person(const Person& p) {
	setName(p.name);
	setAge(p.age+2);
}


Person& Person::operator=(const Person& p) {
	setName(p.name);
	setAge(p.age-2);
}

void Person::setName(string n) { 
	name = n;
}

void Person::setAge(int a) { 
	age = a;
}

void Person::print(){
   cout <<"Name: " << name << "\t\tAge: " << age <<endl;
}

