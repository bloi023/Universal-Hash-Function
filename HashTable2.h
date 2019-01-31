#include <list>
#include <string>
#include <vector>
using namespace std;

class HashTable {
 public:
  HashTable( int size );
  void insert( std::string name );
  void remove( std::string name );
  bool exists( std::string name );
  void print();
  void stat();

 private:
  std::vector<std::list<std::string>> table;
  int hash( std::string name );
  int size;
  int bits;
  std::vector<int> h;
  int a1, a2, a3, a4;
  
  int insertions, deletions;
  int collisions, clocation;
};
