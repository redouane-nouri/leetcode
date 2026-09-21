/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static constexpr int MOD = 1e9 + 7;

public:
  int numberOfSets(const int N, const int K) {
    vector<int> dp(N, 0), preSum(N + 1, 0);

    for (int p = 0; p < N; ++p)
      dp[p] = 1, preSum[p + 1] = (preSum[p] + dp[p]) % MOD;

    dp[0] = 0;
    for (int segCnt = 1; segCnt <= K; ++segCnt) {
      for (int p = 1; p < N; ++p)
        dp[p] = (dp[p - 1] + preSum[p]) % MOD;

      for (int p = 0; p < N; ++p)
        preSum[p + 1] = (preSum[p] + dp[p]) % MOD;
    }

    return dp[N - 1];
  }
};
