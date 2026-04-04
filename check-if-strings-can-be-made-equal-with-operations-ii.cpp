
/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

int eucMod(int a, int b) { return (a % b + abs(b)) % abs(b); };
class Solution {
public:
  bool checkStrings(string s1, string s2) {
    if (s1.size() != s2.size())
      return false;

    int freq[2][26] = {};
    const int N = s1.size();

    for (int i = 0; i < N; ++i)
      ++freq[i % 2][s1[i] - 'a'], --freq[i % 2][s2[i] - 'a'];

    for (int p = 0; p < 2; ++p)
      for (int c = 0; c < 26; ++c)
        if (freq[p][c])
          return false;

    return true;
  }
};
