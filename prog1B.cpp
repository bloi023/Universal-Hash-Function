#include <iostream>
#include "HashTable.h"
#include <fstream>
#include <vector>

using namespace std;

int main(){

  //Convert Input Size into Integer
  std::string s_size;
  cin >> s_size;
  int input_size = std::stoi( s_size );

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
  while( input_size > primelist[i] ) {
    truesize = primelist[i+1];
    i++;
  }
  
  HashTable t( truesize );
  
  std::string next;
  while( cin >> next ) {
    if( next == "stat" )
      t.stat();
    else if( next == "insert" ) {
      cin >> next;
      t.insert(next);
    }
    else if( next == "delete" ) {
      cin >> next;
      t.remove(next);
    }
    else if( next == "lookup" ) {
      cin >> next;
      if( t.exists(next) )
        cout << next << ": found" << endl;
      else
        cout << next << ": not found" << endl;
    }
  }

  //      t.print();
  return 0;

}
