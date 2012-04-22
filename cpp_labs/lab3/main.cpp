#include "person.h"

int main() {
	Person p1;
	p1.setName("Bob");
	p1.setAge(50);

	Person p2;
	p2.setName("Susan");
	p2.setAge(40);

	// Exercise the copy constructor
	Person p3(p1);

	// Create a person and use the assignment operator
	Person p5;
	p5 = p1;

	// Similar to above, but slightly different
	Person p4 = p2;

	// Ditto.
	Person p6;
	p6 = p2;

	p1.print();
	p3.print();
	p5.print();
	p2.print();
	p4.print();
	p6.print();
}

