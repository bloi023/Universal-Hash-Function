#include <iostream>
#include "HashTable.h"

HashTable::HashTable(int size){
	this->size = size;
	table.resize(size);
}

int HashTable::hash(std::string name){
	int val = 0;
	for(int i = 0; i < name.size(); i++){
		val += name[i];
	}
	return val % size;
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


