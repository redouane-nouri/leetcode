/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int maximumSafenessFactor(vector<vector<int>> &grid) {
    queue<array<int, 2>> q;
    const int N = grid.size();

    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j)
        if (grid[i][j] == 1)
          q.push({i, j}), grid[i][j] = 0;
        else
          grid[i][j] = -1;

    int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    const auto areValidIdxs = [&N](const int &i, const int &j) -> bool {
      return i >= 0 && i < N && j >= 0 && j < N;
    };

    while (!q.empty()) {
      int sz = q.size();

      while (sz-- > 0) {
        auto [i, j] = q.front();
        q.pop();

        for (auto &[dx, dy] : dirs) {
          int ni = i + dx, nj = j + dy;

          if (areValidIdxs(ni, nj) && grid[ni][nj] == -1)
            grid[ni][nj] = grid[i][j] + 1, q.push({ni, nj});
        }
      }
    }

    priority_queue<array<int, 3>> pq;
    pq.push({grid[0][0], 0, 0});
    grid[0][0] = -1;

    while (!pq.empty()) {
      auto [sf, i, j] = pq.top();
      pq.pop();

      if (i == N - 1 && j == N - 1)
        return sf;

      for (auto &[dx, dy] : dirs) {
        int ni = i + dx, nj = j + dy;

        if (areValidIdxs(ni, nj) && grid[ni][nj] != -1)
          pq.push({min(sf, grid[ni][nj]), ni, nj}), grid[ni][nj] = -1;
      }
    }

    return -1;
  }
};
