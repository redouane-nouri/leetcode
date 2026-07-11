/**
 * @author Redouane Nouri
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool findSafeWalk(vector<vector<int>> &grid, int health) {
    const int N = grid.size(), M = grid[0].size();
    vector<vector<int>> dist(N, vector<int>(M, INT_MAX));
    deque<pair<int, int>> dq;

    const auto isValidIdxs = [&N, &M](const int i, const int j) -> bool {
      return i >= 0 && j >= 0 && i < N && j < M;
    };

    dist[0][0] = grid[0][0];
    dq.push_front({0, 0});

    int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    while (!dq.empty()) {
      auto [i, j] = dq.front();
      dq.pop_front();

      for (auto &[di, dj] : dirs) {
        int ni = i + di, nj = j + dj;

        if (!isValidIdxs(ni, nj))
          continue;

        if (dist[i][j] + grid[ni][nj] < dist[ni][nj]) {
          dist[ni][nj] = dist[i][j] + grid[ni][nj];

          if (grid[ni][nj])
            dq.push_back({ni, nj});
          else
            dq.push_front({ni, nj});
        }
      }
    }

    return dist[N - 1][M - 1] < health;
  }
};
