run : main.o LCSGenerator.o StringComparer.o
	g++ main.o LCSGenerator.o StringComparer.o -o run

main.o : main.cpp
	g++ -c main.cpp

LCSGenerator.o : LCSGenerator.hpp LCSGenerator.cpp
	g++ -c LCSGenerator.hpp LCSGenerator.cpp

StringComparer.o : StringComparer.hpp StringComparer.cpp
	g++ -c StringComparer.hpp StringComparer.cpp

