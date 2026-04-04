/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumAmount(vector<vector<int>> &coins) {
    const int N = coins[0].size();
    vector dp(N + 1, vector(3, INT_MIN >> 1));

    for (int i = 0; i < 3; ++i)
      dp[1][i] = 0;

    for (auto &r : coins) {
      for (int i = 1; i <= N; ++i) {
        int &c = r[i - 1];

        dp[i][2] =
            max({dp[i - 1][2] + c, dp[i][2] + c, dp[i - 1][1], dp[i][1]});

        dp[i][1] =
            max({dp[i - 1][1] + c, dp[i][1] + c, dp[i - 1][0], dp[i][0]});

        dp[i][0] = max(dp[i - 1][0], dp[i][0]) + c;
      }
    }

    return dp[N][2];
  }
};
