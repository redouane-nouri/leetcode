/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
  static constexpr ll MOD = 1e9 + 7;

public:
  int maxProductPath(vector<vector<int>> &grid) {
    const int M = grid.size(), N = grid[0].size();
    vector<vector<pair<ll, ll>>> dp(M, vector<pair<ll, ll>>(N));

    dp[0][0] = {grid[0][0], grid[0][0]};

    for (int j = 1; j < N; ++j)
      dp[0][j].first = dp[0][j].second = grid[0][j] * dp[0][j - 1].second;

    for (int i = 1; i < M; ++i)
      dp[i][0].first = dp[i][0].second = grid[i][0] * dp[i - 1][0].second;

    for (int i = 1; i < M; ++i) {
      for (int j = 1; j < N; ++j) {
        int &v = grid[i][j];
        ll a = v * dp[i - 1][j].first;
        ll b = v * dp[i - 1][j].second;
        ll c = v * dp[i][j - 1].first;
        ll d = v * dp[i][j - 1].second;

        dp[i][j] = {min({a, b, c, d}), max({a, b, c, d})};
      }
    }

    return dp[M - 1][N - 1].second < 0 ? -1 : dp[M - 1][N - 1].second % MOD;
  }
};
