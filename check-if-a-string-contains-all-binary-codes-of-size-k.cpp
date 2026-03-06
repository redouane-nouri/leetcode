#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool hasAllCodes(string s, int k) {
    const int N = s.size();
    const int distinct = 1 << k;

    if (N < k + distinct - 1)
      return false;

    unordered_set<string> unique;
    const int lastIdx = N - k;

    for (int i = 0; i <= lastIdx; ++i) {
      unique.insert(s.substr(i, k));

      if (unique.size() == distinct)
        return true;

      if (lastIdx - i + unique.size() < distinct)
        return false;
    }

    return unique.size() == distinct;
  }
};
