CXX = g++
CXXFLAGS = -Wall -g

prog1A: HashTable.o prog1A.o
	g++ -g prog1A.o HashTable.o -o prog1A

HashTable.o: HashTable.cpp HashTable.h
	g++ -g -c HashTable.cpp

prog1A.o: prog1A.cpp
	g++ -g -c prog1A.cpp


clean:
	rm *.o -f prog1A 
