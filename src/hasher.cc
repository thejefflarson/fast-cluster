#include <city.h>
#include <hasher.h>
#include <vector>
#include <set>
#include <algorithm>
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

int32_t SimHash(const string& buf, int grams_count) {
  Ngrams grams = ngrams(buf, grams_count);
  vector<int32_t> hashes;

  for(Ngrams::iterator it = grams.begin(); it != grams.end(); ++it)
    if(it->length() > 0)
      hashes.push_back(CityHash32(it->c_str(), it->length()));

  sort(hashes.begin(), hashes.end());

  return hashes.front();
}

}

