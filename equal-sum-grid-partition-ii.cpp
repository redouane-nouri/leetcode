/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
  vector<vector<int>> rotate(vector<vector<int>> &grid) {
    const int M = grid.size(), N = grid[0].size();
    vector<vector<int>> ans(N, vector<int>(M));

    for (int i = 0; i < M; ++i)
      for (int j = 0; j < N; ++j)
        ans[j][M - i - 1] = grid[i][j];

    return ans;
  }

public:
  bool canPartitionGrid(vector<vector<int>> &grid) {
    const int MM = grid.size(), NN = grid[0].size();
    ll tot = 0;

    for (int i = 0; i < MM; ++i)
      for (int j = 0; j < NN; ++j)
        tot += grid[i][j];

    for (int k = 0; k < 4; ++k) {
      unordered_set<ll> seen;
      ll upperSum = 0, diff;
      seen.insert(0);

      const int M = grid.size(), N = grid[0].size();

      if (N == 1) {
        for (int i = 0; i < M - 1; ++i) {
          upperSum += grid[i][0];
          diff = (upperSum << 1) - tot;

          if (!diff || diff == grid[0][0] || diff == grid[i][0])
            return true;
        }
      } else if (M > 1) {
        for (int i = 0; i < M - 1; ++i) {
          for (int j = 0; j < N; ++j) {
            seen.insert(grid[i][j]);
            upperSum += grid[i][j];
          }

          diff = (upperSum << 1) - tot;

          if (i == 0) {
            if (diff == 0 || diff == grid[0][0] || diff == grid[0][N - 1])
              return true;
          } else {
            if (seen.contains(diff))
              return true;
          }
        }
      }

      grid = rotate(grid);
    }

    return false;
  }
};
