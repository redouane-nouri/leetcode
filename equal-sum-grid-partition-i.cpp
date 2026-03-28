/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution {
public:
  bool canPartitionGrid(vector<vector<int>> &grid) {
    const int M = grid.size(), N = grid[0].size();
    vector<vector<ll>> pre(M + 1, vector<ll>(N + 1, 0));
    ll tot = 0;

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        pre[i + 1][j + 1] =
            pre[i + 1][j] + pre[i][j + 1] - pre[i][j] + grid[i][j];
        tot += grid[i][j];
      }
    }

    if (tot % 2)
      return false;

    tot >>= 1;

    for (int i = 1; i < M; ++i)
      if (pre[i][N] == tot)
        return true;

    for (int j = 1; j < N; ++j)
      if (pre[M][j] == tot)
        return true;

    return false;
  }
};
