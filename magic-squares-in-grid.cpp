#include <vector>

class Solution {
public:
  int numMagicSquaresInside(std::vector<std::vector<int>> &grid) {
    const int M = grid.size(), N = grid[0].size();
    std::vector<std::vector<int>> preSumRows(M, std::vector<int>(N + 1, 0)),
        preSumCols(M + 1, std::vector<int>(N, 0));

    for (int i = 0; i < M; ++i) {
      for (int j = 0; j < N; ++j) {
        preSumRows[i][j + 1] = preSumRows[i][j] + grid[i][j];
        preSumCols[i + 1][j] = preSumCols[i][j] + grid[i][j];
      }
    }

    int ans = 0;
    for (int i = 0; i < M - 2; ++i) {
      for (int j = 0; j < N - 2; ++j) {
        if (grid[i][j] == 0 || grid[i][j] > 9)
          continue;

        bool seen[10] = {false}, unique = true;

        for (int k = 0; k < 3 && unique; ++k) {
          for (int l = 0; l < 3 && unique; ++l) {
            int v = grid[i + k][j + l];
            if (v == 0 || v > 9)
              unique = false;
            else
              unique = seen[v] = !seen[v];
          }
        }

        if (!unique)
          continue;

        int d1 = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int d2 = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
        int r1 = preSumRows[i][j + 3] - preSumRows[i][j];
        int r2 = preSumRows[i + 1][j + 3] - preSumRows[i + 1][j];
        int r3 = preSumRows[i + 2][j + 3] - preSumRows[i + 2][j];
        int c1 = preSumCols[i + 3][j] - preSumCols[i][j];
        int c2 = preSumCols[i + 3][j + 1] - preSumCols[i][j + 1];
        int c3 = preSumCols[i + 3][j + 2] - preSumCols[i][j + 2];

        if (d1 == d2 && d1 == r1 && d1 == r2 && d1 == r3 && d1 == c1 &&
            d1 == c2 && d1 == c3)
          ++ans;
      }
    }

    return ans;
  }
};
