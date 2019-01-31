#include <iostream>
#include "HashTable2.h"
#include <fstream>
#include <vector>

using namespace std;

int main(){

  //Convert Input Size into Integer
  std::string s_size;
  cin >> s_size;
  int input_size = std::stoi( s_size );
 
  HashTable t( input_size );
  
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
  
  return 0;

}
