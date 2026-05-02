/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  long long maximumScore(vector<vector<int>> &grid) {
    int N = grid[0].size();
    if (N == 1)
      return 0;

    vector<vector<vector<ll>>> dp(N, vector(N + 1, vector<ll>(N + 1, 0)));
    vector<vector<ll>> colSum(N, vector<ll>(N + 1, 0));

    for (int c = 0; c < N; ++c)
      for (int r = 1; r <= N; ++r)
        colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];

    vector<vector<ll>> prevMax(N + 1, vector<ll>(N + 1, 0));
    vector<vector<ll>> prevSuffixMax(N + 1, vector<ll>(N + 1, 0));

    for (int i = 1; i < N; ++i) {
      for (int cur = 0; cur <= N; ++cur) {
        for (int prev = 0; prev <= N; ++prev) {
          ll extra;

          if (cur <= prev) {
            extra = colSum[i][prev] - colSum[i][cur];
            dp[i][cur][prev] =
                max(dp[i][cur][prev], prevSuffixMax[prev][0] + extra);
          } else {
            extra = colSum[i - 1][cur] - colSum[i - 1][prev];
            dp[i][cur][prev] = max({dp[i][cur][prev], prevSuffixMax[prev][cur],
                                    prevMax[prev][cur] + extra});
          }
        }
      }

      for (int cur = 0; cur <= N; ++cur) {
        prevMax[cur][0] = dp[i][cur][0];

        for (int prev = 1; prev <= N; ++prev) {
          ll p = (prev > cur) ? (colSum[i][prev] - colSum[i][cur]) : 0;

          prevMax[cur][prev] =
              max(prevMax[cur][prev - 1], dp[i][cur][prev] - p);
        }

        prevSuffixMax[cur][N] = dp[i][cur][N];

        for (int p = N - 1; p >= 0; --p)
          prevSuffixMax[cur][p] = max(prevSuffixMax[cur][p + 1], dp[i][cur][p]);
      }
    }

    ll ans = 0;
    for (int h = 0; h <= N; ++h)
      ans = max({ans, dp[N - 1][N][h], dp[N - 1][0][h]});

    return ans;
  }
};
