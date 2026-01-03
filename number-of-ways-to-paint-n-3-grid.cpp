#include <array>
#include <vector>

class Solution {
public:
  int numOfWays(int n) {
    const long long MOD = 1'000'000'007;
    std::vector<std::array<long long, 2>> dp(n, {0, 0});

    dp[0][0] = 6;
    dp[0][1] = 6;

    for (int i = 1; i < n; ++i) {
      dp[i][0] = (dp[i - 1][0] * 3 + dp[i - 1][1] * 2) % MOD;
      dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1] * 2) % MOD;
    }

    return (dp[n - 1][0] + dp[n - 1][1]) % MOD;
  }
};
