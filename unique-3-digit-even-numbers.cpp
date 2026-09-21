/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int totalNumbers(vector<int> &digits) {
    array<int, 10> cnt;
    cnt.fill(0);

    for (const int &d : digits)
      ++cnt[d];

    int ans = 0;
    for (int h = 1; h <= 9; ++h) {
      if (cnt[h] == 0)
        continue;

      --cnt[h];

      for (int u = 0; u <= 8; u += 2) {
        if (cnt[u] == 0)
          continue;

        --cnt[u];

        for (int t = 0; t <= 9; ++t)
          if (cnt[t] > 0)
            ++ans;

        ++cnt[u];
      }

      ++cnt[h];
    }

    return ans;
  }
};
