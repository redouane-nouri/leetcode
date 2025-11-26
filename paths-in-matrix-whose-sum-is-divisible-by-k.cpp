#include <vector>

class Solution {
public:
  int numberOfPaths(std::vector<std::vector<int>> &grid, int k) {
    const int M = grid.size(), N = grid[0].size(), MOD = 1'000'000'007;
    std::vector<std::vector<std::vector<int>>> dp(
        M, std::vector<std::vector<int>>(N, std::vector<int>(k, 0)));

    dp[0][0][grid[0][0] % k] = 1;

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int r = 0; r < k; ++r) {
          int nr = (grid[i][j] + r) % k;

          if (i > 0) {
            dp[i][j][nr] = (dp[i][j][nr] + dp[i - 1][j][r]) % MOD;
          }

          if (j > 0) {
            dp[i][j][nr] = (dp[i][j][nr] + dp[i][j - 1][r]) % MOD;
          }
        }
      }
    }

    return dp[M - 1][N - 1][0];
  }
};
