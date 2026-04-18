/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
  static constexpr ll INF = 1e18;

public:
  long long minimumTotalDistance(vector<int> &robot,
                                 vector<vector<int>> &factory) {
    sort(robot.begin(), robot.end()), sort(factory.begin(), factory.end());
    const int N = robot.size(), M = factory.size();

    vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, INF));

    for (int j = 0; j <= M; ++j)
      dp[0][j] = 0;

    for (int j = 1; j <= M; ++j) {
      int &pos = factory[j - 1][0], &lim = factory[j - 1][1];

      for (int i = 1; i <= N; ++i) {
        dp[i][j] = dp[i][j - 1];
        ll c = 0;

        for (int k = 1; k <= min(i, lim); ++k) {
          c += abs(robot[i - k] - pos);
          dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + c);
        }
      }
    }

    return dp[N][M];
  }
};
