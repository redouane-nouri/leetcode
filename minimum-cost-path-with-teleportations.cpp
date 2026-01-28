#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int minCost(vector<vector<int>> &grid, int k) {
    const int M = grid.size(), N = grid[0].size();
    vector<pair<int, int>> ordered;
    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        ordered.push_back({i, j});
    sort(ordered.begin(), ordered.end(),
         [&grid](const auto &a, const auto &b) -> bool {
           return grid[a.first][a.second] < grid[b.first][b.second];
         });
    vector<vector<int>> costs(M, vector<int>(N, INT_MAX));
    for (int t = 0; t <= k; ++t) {
      int minCost = INT_MAX;
      for (int start = 0, end = 0; end < N * M; ++end) {
        minCost = min(minCost, costs[ordered[end].first][ordered[end].second]);
        if (end + 1 < N * M &&
            grid[ordered[end].first][ordered[end].second] ==
                grid[ordered[end + 1].first][ordered[end + 1].second])
          continue;
        for (int i = start; i <= end; ++i)
          costs[ordered[i].first][ordered[i].second] = minCost;
        start = end + 1;
      }
      for (int i = M - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
          if (i == M - 1 && j == N - 1)
            costs[M - 1][N - 1] = 0;
          if (i + 1 < M)
            costs[i][j] = min(costs[i][j], costs[i + 1][j] + grid[i + 1][j]);
          if (j + 1 < N)
            costs[i][j] = min(costs[i][j], costs[i][j + 1] + grid[i][j + 1]);
        }
      }
    }
    return costs[0][0];
  }
};
