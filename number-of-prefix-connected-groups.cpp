#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int prefixConnected(vector<string> &words, int k) {
    unordered_map<string, int> mp;

    for (const string &w : words)
      if (w.size() >= k)
        ++mp[w.substr(0, k)];

    int ans = 0;

    for (const auto &[k, v] : mp)
      ans += v > 1 ? 1 : 0;

    return ans;
  }
};
