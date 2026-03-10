/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numberOfStableArrays(const int zero, const int one, const int limit) {
    const int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp(
        zero + 1, vector<vector<int>>(one + 1, vector<int>(2, 0)));

    for (int z = 0; z <= zero; ++z) {
      for (int o = 0; o <= one; ++o) {
        for (int b = 0; b < 2; ++b) {
          if (z == 0 || o == 0) {
            dp[z][o][b] = (b == 0) ? (z <= limit && o == 0 ? 1 : 0)
                                   : (o <= limit && z == 0 ? 1 : 0);
            continue;
          }

          if (b) {
            dp[z][o][1] = (dp[z][o - 1][0] + dp[z][o - 1][1]) % MOD;

            if (o > limit)
              dp[z][o][1] = (dp[z][o][1] - dp[z][o - limit - 1][0] + MOD) % MOD;

            continue;
          }

          dp[z][o][0] = (dp[z - 1][o][0] + dp[z - 1][o][1]) % MOD;

          if (z > limit)
            dp[z][o][0] = (dp[z][o][0] - dp[z - limit - 1][o][1] + MOD) % MOD;
        }
      }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
  }
};
