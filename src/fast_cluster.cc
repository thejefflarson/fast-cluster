#include "hasher.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){
  ifstream ifs = ifstream(argv[1]);
  if(argc != 3) {
    cout << "usage: fast-cluster file <ngrams>" << endl;
    return 1;
  }
  string buf;
  if(ifs) {
    ifs.seekg(0, ios::end);
    buf.resize(ifs.tellg());
    ifs.seekg(0, ios::beg);
    ifs.read(&buf[0], buf.size());
    ifs.close();
    cout << fast_cluster::SimHash(buf, stoi(argv[2])) << "\t" << argv[1] << endl;
  } else {
    cout << "couldn't find " << argv[1] << endl;
  }

  return 0;
}
