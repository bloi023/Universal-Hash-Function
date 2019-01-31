#include <iostream>
#include <string>
#include "HashTable2.h"
#include <bitset>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

HashTable::HashTable(int size){
  
  //Find Smallest Prime larger than input size
  std::vector<int> primelist;
  primelist.push_back(2);
  primelist.push_back(3);
  primelist.push_back(5);
  primelist.push_back(11);
  primelist.push_back(17);
  primelist.push_back(37);
  primelist.push_back(67);
  primelist.push_back(131);
  primelist.push_back(257);
  primelist.push_back(521);
  primelist.push_back(1031);
  primelist.push_back(2053);
  primelist.push_back(4099);
  primelist.push_back(8209);
  primelist.push_back(16411);
  primelist.push_back(32771);
  primelist.push_back(65537);
  primelist.push_back(131101);
  primelist.push_back(262147);
  primelist.push_back(524309);
  
  int truesize = 0;
  int i = 0;
  while( size > primelist[i] ) {
    truesize = primelist[i+1];
    i++;
  }
 
  this->size = truesize;
  table.resize(truesize);
  
  bits = (log(size)/log(2));
  
  srand( time(0) );
  int mod = 32 % bits;
  int hashnumber;
  if( mod == 0 )
    hashnumber = 32/bits;
  else
    hashnumber = 32/bits + 1;

  for(int i = 0; i < hashnumber; i++ ) {
    h.push_back(rand()%truesize);
  }
  
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

  //Convert to Binary String
  string s1 = bitset<8>(x1).to_string();
  string s2 = bitset<8>(x2).to_string();
  string s3 = bitset<8>(x3).to_string();
  string s4 = bitset<8>(x4).to_string();
  string address_string = s1+s2+s3+s4;
  
  //Convert to vector of dec numbers of n bits
  int mod = 32%bits;
  int start = 32;
  string temp;
  int dec, base;
  int hashnumber2;
  if( mod == 0 )
    hashnumber2 = 32/bits;
  else
    hashnumber2 = 32/bits + 1;

  std::vector<int> a;
  for( int i = 0; i < hashnumber2; i++ ) {
    if( i == hashnumber2 - 1 ) {
      if(mod == 0)
	temp = address_string.substr(0, bits);
      else
	temp = address_string.substr( 0, mod);
    }
    else {
      temp = address_string.substr(start - bits, bits);
      start -= bits;
    }

    
    dec = 0; base = 0;
    for( int j = temp.length() - 1; j >= 0; j-- ) {
      if(temp[j] == '1')
	dec += pow(2, base);
      base++;
    }
    
    a.push_back( dec );
    
  }
  

  //Hash the Adress
  int answer = 0;
  for( int i = 0; i < a.size(); i++ ) {
    answer+= a[i]*h[i];
  }
  return answer%size;
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
  for( int i = 0; i < h.size(); i++ ) {
    if( i== h.size() - 1 )
      cout << h[i] << endl;
    else
      cout << h[i] << " ";
  } 
  
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
