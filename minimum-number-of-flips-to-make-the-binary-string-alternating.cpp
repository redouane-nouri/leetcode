#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int minFlips(string s) {
    string ss = s + s;
    const int NN = ss.size(), N = s.size();
    string pattern1, pattern2;

    pattern1.reserve(NN), pattern2.reserve(NN);

    for (int i = 0; i < NN; ++i) {
      pattern1 += (i % 2 == 0) ? '1' : '0';
      pattern2 += (i % 2 == 0) ? '0' : '1';
    }

    int cost1 = 0, cost2 = 0, ans = INT_MAX;

    for (int i = 0; i < NN; ++i) {
      if (ss[i] != pattern1[i])
        ++cost1;

      if (ss[i] != pattern2[i])
        ++cost2;

      if (i >= N) {
        if (ss[i - N] != pattern1[i - N])
          --cost1;

        if (ss[i - N] != pattern2[i - N])
          --cost2;
      }

      if (i >= N - 1)
        ans = min(ans, min(cost1, cost2));
    }

    return ans;
  }
};
