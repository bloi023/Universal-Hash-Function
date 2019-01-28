#include <iostream>
#include "HashTable.h"
#include <fstream>
using namespace std;

int main(){
  
	std::string s_size;
	cin >> s_size;
	int truesize = std::stoi( s_size );
	
	HashTable t( 257 );

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

	//	t.print();
	return 0;

}
