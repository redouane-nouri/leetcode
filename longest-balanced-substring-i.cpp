#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int longestBalanced(string s) {
    const int N = s.size();
    int ans = 0;
    for (int i = 0; i < N && N - i > ans; ++i) {
      int freq[26] = {0};
      int dist = 0;
      int maxFreq = 0;
      int l = 1;

      for (int j = i; j < N; ++j, ++l) {
        int k = s[j] - 'a';

        dist += freq[k] == 0;
        maxFreq = max(maxFreq, ++freq[k]);

        if (l == maxFreq * dist)
          ans = max(ans, l);
      }
    }
    return ans;
  }
};
