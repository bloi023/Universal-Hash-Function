#include <iostream>
#include "HashTable.h"
#include <fstream>
using namespace std;

int main(){
	
	ofstream input;
	input.open("input.txt");
	
	std::string s_size;
	std::getline( std::input, s_size );
	int size = std::stoi( s_size );
	HashTable t(size);

	return 0;

}
