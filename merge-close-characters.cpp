#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string mergeCharacters(string s, int k) {
    int n = s.size();

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j] && j - i <= k) {
          --n;
          s.erase(j, 1);
          i = max(-1, j - k - 1);
          break;
        }
      }
    }

    return s;
  }
};
