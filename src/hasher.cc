#include <city.h>
#include <hasher.h>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

namespace fast_cluster {

typedef vector<string> Ngrams;

Ngrams ngrams(const string& buf, int num){
  size_t offset = 0, length = buf.length();
  Ngrams grams;

  while(offset < length) {
    // Scan through the string for the number of grams
    size_t goffset = offset;
    for(int i = 0; i < num; i++) {
      goffset = buf.find(" ", goffset + 1);

      if(goffset == string::npos) {
        goffset = buf.length();
        break;
      }
    }

    grams.push_back(buf.substr(offset, goffset - offset));

    offset = buf.find(" ", offset + 1);
  }

  return grams;
}

int64_t SimHash(const string& buf, int grams_count, int iters) {
  Ngrams grams = ngrams(buf, grams_count);
  int64_t hash = 0;
  set<int64_t> hashes;

  for(Ngrams::iterator it = grams.begin(); it != grams.end(); ++it)
    hashes.insert(CityHash64(it->c_str(), it->length()));

  int i = 0;
  for(set<int64_t>::iterator hit = hashes.begin(); hit != hashes.end(); ++hit, i++) {
    hash ^= *hit;
    if(i >= iters) break;
  }

  return hash;
}

}

