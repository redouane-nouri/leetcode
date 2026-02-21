#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countBinarySubstrings(string s) {
    int prev = 0, curr = 1, ans = 0;
    const int N = s.size();

    for (int i = 1; i < N; ++i) {
      if (s[i] == s[i - 1]) {
        ++curr;
      } else {
        ans += min(prev, curr);
        prev = curr;
        curr = 1;
      }
    }

    ans += min(prev, curr);
    return ans;
  }
};
