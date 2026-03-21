/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int countSubmatrices(vector<vector<int>> &grid, int k) {
    const int M = grid.size(), N = grid[0].size();

    for (int i = 1; i < M; ++i)
      grid[i][0] += grid[i - 1][0];

    for (int j = 1; j < N; ++j)
      grid[0][j] += grid[0][j - 1];

    for (int i = 1; i < M; ++i)
      for (int j = 1; j < N; ++j)
        grid[i][j] += grid[i - 1][j] - grid[i - 1][j - 1] + grid[i][j - 1];

    int ans = 0;
    for (int i = 0; i < M; ++i) {
      int j = 0;

      while (j < N && grid[i][j] <= k)
        ++j, ++ans;
    }

    return ans;
  }
};
