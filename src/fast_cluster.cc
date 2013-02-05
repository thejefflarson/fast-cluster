#include "hasher.h"
#include <iostream>
#include <fstream>

namespace std {
int main(int argc, char *argv[]){
  if(argc != 2) abort();
  ifstream ifs = ifstream(argv[1]);

  string buf;
  while(ifs.good())
    ifs >> buf;
  ifs.close();

  cout << fast_cluster::SimHash(buf, 10) << endl;

  return 0;
}
}
