#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(int size){
	this->size = size;
	table.resize(size);
	
	srand( time(0) );
	a1 = rand()%257;
	a2 = rand()%257;
	a3 = rand()%257;
	a4 = rand()%257;
	
	//a1 = 10; a2 = 89; a3 = 210; a4 = 162;
	insertions = 0;
	deletions = 0;

	collisions = 0;
	clocation = 0;

}

int HashTable::hash(std::string address){
  int x1, x2, x3, x4;
  int d1, d2, d3;
  d1 = address.find( ".", 0 );
  d2 = address.find( ".", d1+1);
  d3 = address.find( ".", d2+1);
  
  x1 = std::stoi( address.substr( 0, d1) );
  x2 = std::stoi( address.substr( d1+1, d2-d1-1) );
  x3 = std::stoi( address.substr( d2+1, d3-d2-1) );
  x4 = std::stoi( address.substr( d3+1 ) );

  return ( ((a1*x4)+(a2*x3)+(a3*x2)+(a4*x1))%257 );
}

bool HashTable::exists(std::string address){
	int index = hash(address);
	std::list<std::string>::iterator it;
	for(it = table[index].begin(); it != table[index].end(); it++){
			if(address.compare(*it) == 0){
				return true;
			}
	}
	return false;
}

void HashTable::insert(std::string address){
	if(exists(address)){
	  std::cout << "Error : could not insert " << address << "  because it already exists." << endl;
	  return;
	}
	
	insertions++;
	int index = hash(address);
	table[index].push_back(address);
	
	if( table[index].size() > collisions ) {
	  collisions = table[index].size();
	  clocation = index;
	}
	else if( table[index].size() == collisions && index > clocation ) {
	  clocation = index;
	}
	
	//std::cout << address << " inserted" << std::endl;
	return;
}

void HashTable::remove(std::string address){
	int index = hash(address);
	std::list<std::string>::iterator it;
	for(it = table[index].begin(); it != table[index].end(); it++){
		if(address.compare(*it) == 0){
			table[index].erase(it);
			//std::cout << address << " deleted" << std::endl;
			deletions++;
			return;
		}
	}
	std::cout << "Error : could not delete " << address << " because it does not exist." << std::endl;
	return;
}

void HashTable::print() {
	for(int i = 0; i < size; i++){
		std::list<std::string>::iterator it;
		std::cout << i << ": ";
		for(it = table[i].begin(); it != table[i].end(); it++){
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
	}
}

void HashTable::stat() {
  cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
  cout << insertions << endl;
  cout << deletions << endl;

  int emptyslots = 0;
  int oneitemslots = 0;
  
  for( int i = 0; i < size; i++ ) {
    if( table[i].size() == 0 )
      emptyslots++;
  }

  for( int i = 0; i < size; i++ ) {
    if( table[i].size() == 1 )
      oneitemslots++;
  }

  cout << emptyslots << endl;
  cout << oneitemslots << endl;
  cout << collisions << " " << clocation << endl;
}
