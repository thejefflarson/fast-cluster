#include "hasher.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){
  if(argc != 2) {
    cerr << "usage: fast_cluster <file>" << std::endl;
    exit(1);
  }

  ifstream ifs = ifstream(argv[1]);

  string buf;
  if(ifs) {
    ifs.seekg(0, ios::end);
    buf.resize(ifs.tellg());
    ifs.seekg(0, ios::beg);
    ifs.read(&buf[0], buf.size());
    ifs.close();
    cout << fast_cluster::SimHash(buf, 10) << endl;
  } else {
    printf("couldn't find %s\n", argv[1]);
  }

  return 0;
}
