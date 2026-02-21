#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minimumDeletions(string s) {
    int bs = 0;
    int deletions = 0;

    for (const char &c : s) {
      if (c == 'b')
        ++bs;
      else
        deletions = min(deletions + 1, bs);
    }

    return deletions;
  }
};
