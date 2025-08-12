#include <cmath>
#include <vector>

class Solution {
  constexpr static int MOD = 1'000'000'007;

public:
  int numberOfWays(int n, int x) {
    std::vector<int> powers;

    powers.push_back(1);
    for (int i = 2; i <= n; ++i) {
      int val = i;
      for (int j = 2; j <= x; ++j)
        val *= i;

      if (val > n)
        break;

      powers.push_back(val);
    }

    int cols = powers.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(cols + 1));

    for (int i = 0; i <= cols; ++i)
      dp[0][i] = 1;

    for (int j = 1; j <= n; ++j)
      dp[j][0] = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= cols; ++j) {
        if (powers[j - 1] <= i) {
          dp[i][j] = (dp[i][j - 1] + dp[i - powers[j - 1]][j - 1]) % MOD;
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      }
    }

    return dp[n][cols];
  }
};
