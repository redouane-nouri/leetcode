/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool hasValidPath(vector<vector<char>> &grid) {
    const int M = grid.size(), N = grid[0].size();

    if ((M + N - 1) % 2 == 1)
      return false;

    if (grid[0][0] == ')' || grid[M - 1][N - 1] == '(')
      return false;

    vector dp(M, vector<bitset<101>>(N, bitset<101>(0)));
    dp[0][0].set(1);

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        if (i == 0 && j == 0)
          continue;

        auto &cur = dp[i][j];

        if (i > 0)
          cur |= dp[i - 1][j];

        if (j > 0)
          cur |= dp[i][j - 1];

        grid[i][j] == '(' ? cur <<= 1 : cur >>= 1;
      }
    }

    return dp[M - 1][N - 1].test(0);
  }
};
