/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<vector<int>> rotateGrid(vector<vector<int>> &grid, const int k) {
    const int M = grid.size(), N = grid[0].size(), L = min(M, N) / 2;

    for (int l = 0; l < L; l++) {
      vector<int> v;

      for (int c = l; c < N - l; c++)
        v.push_back(grid[l][c]);

      for (int r = l + 1; r < M - l; r++)
        v.push_back(grid[r][N - l - 1]);

      for (int c = N - l - 2; c >= l; c--)
        v.push_back(grid[M - l - 1][c]);

      for (int r = M - l - 2; r > l; r--)
        v.push_back(grid[r][l]);

      const int sz = v.size();
      vector<int> rotated(sz);
      for (int i = 0; i < sz; i++)
        rotated[i] = v[(i + (k % sz)) % sz];

      int idx = 0;

      for (int c = l; c < N - l; c++)
        grid[l][c] = rotated[idx++];

      for (int r = l + 1; r < M - l; r++)
        grid[r][N - l - 1] = rotated[idx++];

      for (int c = N - l - 2; c >= l; c--)
        grid[M - l - 1][c] = rotated[idx++];

      for (int r = M - l - 2; r > l; r--)
        grid[r][l] = rotated[idx++];
    }

    return grid;
  }
};
