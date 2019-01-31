CXX = g++
CXXFLAGS = -Wall -g

prog1A: HashTable.o prog1A.o
	g++ -g prog1A.o HashTable.o -o prog1A

prog1B: HashTable2.o prog1B.o
	g++ -g prog1B.o HashTable2.o -o prog1B

HashTable.o: HashTable.cpp HashTable.h
	g++ -g -c HashTable.cpp

HashTable2.o: HashTable2.cpp HashTable2.h
	g++ -g -c HashTable2.cpp

prog1A.o: prog1A.cpp
	g++ -g -c prog1A.cpp

prog1B.o: prog1B.cpp
	g++ -g -c prog1B.cpp

clean:
	rm *.o -f prog1A prog1B
