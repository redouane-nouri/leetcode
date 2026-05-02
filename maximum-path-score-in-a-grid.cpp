/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maxPathScore(vector<vector<int>> &grid, int k) {
    const int N = grid.size(), M = grid[0].size();
    vector<vector<vector<int>>> dp(2, vector(M, vector<int>(k + 1, -1)));

    dp[0][0][0] = 0;

    int ans = -1;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        for (int c = 0; c <= k; ++c) {
          if (dp[0][j][c] == -1)
            continue;

          if (i + 1 < N) {
            int &v = grid[i + 1][j];
            int nc = c + (v == 0 ? 0 : 1);

            if (nc <= k)
              dp[1][j][nc] = max(dp[1][j][nc], dp[0][j][c] + v);
          }

          if (j + 1 < M) {
            int &v = grid[i][j + 1];
            int nc = c + (v == 0 ? 0 : 1);

            if (nc <= k)
              dp[0][j + 1][nc] = max(dp[0][j + 1][nc], dp[0][j][c] + v);
          }

          if (i == N - 1 && j == M - 1)
            ans = max(ans, dp[0][j][c]);

          dp[0][j][c] = -1;
        }
      }

      swap(dp[0], dp[1]);
    }

    return ans;
  }
};
