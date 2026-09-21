/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  int minDays(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    vector<int> TR;
    TR.reserve(sqrt(n << 1));

    for (int day = 0;; ++day) {
      ll t = day * (day + 1) >> 1;
      if (t > n)
        break;

      TR.push_back(t);
    }

    for (int sum = 1; sum <= n; ++sum) {
      for (int day = 1; day < TR.size(); ++day) {
        int t = TR[day];

        if (t > sum)
          break;

        int rem = sum - t;

        if (rem == 0)
          dp[sum] = min(dp[sum], day);
        else if (dp[rem] != INT_MAX)
          dp[sum] = min(dp[sum], day + 1 + dp[rem]);
      }
    }

    return dp[n];
  }
};
