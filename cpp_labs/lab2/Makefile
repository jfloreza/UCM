program: main.cpp Student.o Person.o Doctor.o
	g++ main.cpp Student.o Person.o Doctor.o -o program
	
Student.o: Student.h Student.cpp
	g++ -c Student.cpp
	
Person.o: Person.h Person.cpp
	g++ -c Person.cpp

Doctor.o: Doctor.h Doctor.cpp
	g++ -c Doctor.cpp
