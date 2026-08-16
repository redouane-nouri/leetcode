/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int stoneGameII(vector<int> &piles) {
    const int SZ = piles.size();
    vector<vector<int>> dp(SZ + 1, vector<int>(SZ + 1, 0));
    vector<int> sufSum(SZ + 1);

    for (int i = SZ - 1; i >= 0; --i)
      sufSum[i] = piles[i] + sufSum[i + 1];

    for (int i = 0; i <= SZ; ++i)
      dp[i][SZ] = sufSum[i];

    for (int i = SZ - 1; i >= 0; --i)
      for (int m = SZ - 1; m > 0; --m)
        for (int x = 1; x <= m << 1 && i + x <= SZ; ++x)
          dp[i][m] = max(dp[i][m], sufSum[i] - dp[i + x][max(m, x)]);

    return dp[0][1];
  }
};
