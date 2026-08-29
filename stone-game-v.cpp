/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
  vector<vector<int>> dp;
  vector<int> sv, preSum;

  int dfs(int l, int r) {
    if (l == r)
      return 0;

    if (dp[l][r])
      return dp[l][r];

    for (int m = l; m < r; ++m) {
      int ls = preSum[m + 1] - preSum[l], rs = preSum[r + 1] - preSum[m + 1];

      if (ls < rs)
        dp[l][r] = max(dp[l][r], ls + dfs(l, m));
      else if (ls > rs)
        dp[l][r] = max(dp[l][r], rs + dfs(m + 1, r));
      else
        dp[l][r] = max(dp[l][r], ls + max(dfs(l, m), dfs(m + 1, r)));
    }

    return dp[l][r];
  }

public:
  int stoneGameV(vector<int> &stoneValue) {
    const int SZ = stoneValue.size();

    preSum.assign(SZ + 1, 0);
    for (int i = 0; i < SZ; ++i)
      preSum[i + 1] = preSum[i] + stoneValue[i];

    sv = move(stoneValue);
    dp.assign(SZ, vector<int>(SZ, 0));

    return dfs(0, SZ - 1);
  }
};
