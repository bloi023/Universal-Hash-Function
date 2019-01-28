#include <iostream>
#include <string>
#include "HashTable.h"

using namespace std;

HashTable::HashTable(int size){
	this->size = size;
	table.resize(size);
	a1 = rand()%257;
	a2 = rand()%257;
	a3 = rand()%257;
	a4 = rand()%257;
}

int HashTable::hash(std::string address){
  int x1, x2, x3, x4;
  int d1, d2, d3;
  d1 = address.find( ".", 0 );
  d2 = address.find( ".", d1+1);
  d3 = address.find( ".", d2+1);
  
  x1 = std::stoi( adress.substr( 0, d1) );
  x2 = std::stoi( address.substr( d1+1, d2-d1-1) );
  x3 = std::stoi( address.substr( d2+1, d3-d2-1) );
  x4 = std::stoi( address.substr( d3+1, address.length()-d3-1 ) );

  return (a1*x1+a2*x2+a3*x3+a4*x4)%size;
}

bool HashTable::exists(std::string name){
	int index = hash(name);
	std::list<std::string>::iterator it;
	for(it = table[index].begin(); it != table[index].end(); it++){
			if(name.compare(*it) == 0){
				return true;
			}
	}
	return false;
}

void HashTable::insert(std::string name){
	if(exists(name)){
		std::cout << name << " already exists" << std::endl;
		return;
	}
	int index = hash(name);
	table[index].push_back(name);
	std::cout << name << " inserted" << std::endl;
	return;
}

void HashTable::remove(std::string name){
	int index = hash(name);
	std::list<std::string>::iterator it;
	for(it = table[index].begin(); it != table[index].end(); it++){
		if(name.compare(*it) == 0){
			table[index].erase(it);
			std::cout << name << " deleted" << std::endl;
			return;
		}
	}
	std::cout << name << " does not exist" << std::endl;
	return;
}

void HashTable::print(){
	for(int i = 0; i < size; i++){
		std::list<std::string>::iterator it;
		std::cout << i << ": ";
		for(it = table[i].begin(); it != table[i].end(); it++){
			std::cout << *it << ' ';
		}
		std::cout << std::endl;
	}
}


