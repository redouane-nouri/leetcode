/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
  static constexpr int MOD = 1e9 + 7;

public:
  int distinctSubseqII(string s) {
    const int N = s.size();
    vector<int> dp(N + 1), last(26, -1);
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
      dp[i + 1] = (dp[i] << 1) % MOD;

      int idx = s[i] - 'a';

      if (last[idx] >= 0)
        dp[i + 1] = (dp[i + 1] - dp[last[idx]]) % MOD;

      last[idx] = i;
    }

    return (--dp[N] + MOD) % MOD;
  }
};
