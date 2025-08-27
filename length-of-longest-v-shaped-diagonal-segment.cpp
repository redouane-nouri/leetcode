#include <vector>

class Solution {
  const int NO_TURN = 0, TURNED = 1, DOWN_RIGHT = 0, DOWN_LEFT = 1, UP_LEFT = 2,
            UP_RIGHT = 3, STEP_DOWN = +1, STEP_UP = -1, STEP_RIGHT = +1,
            STEP_LEFT = -1, SEQ[3] = {2, 2, 0},
            DX[4] = {STEP_DOWN, STEP_DOWN, STEP_UP, STEP_UP},
            DY[4] = {STEP_RIGHT, STEP_LEFT, STEP_LEFT, STEP_RIGHT},
            CLOCKWISE[4] = {DOWN_LEFT, UP_LEFT, UP_RIGHT, DOWN_RIGHT};

  int m, n;
  std::vector<std::vector<std::vector<std::vector<int>>>> dp;

  int exploreDP(const std::vector<std::vector<int>> &grid, int i, int j,
                int dir, int turnState) {
    if (dp[i][j][dir][turnState] != -1)
      return dp[i][j][dir][turnState];

    int len = 1, nextVal = SEQ[grid[i][j]], ni = i + DX[dir], nj = j + DY[dir];

    if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == nextVal)
      len = 1 + exploreDP(grid, ni, nj, dir, turnState);

    if (turnState == NO_TURN) {
      int newDir = CLOCKWISE[dir], ti = i + DX[newDir], tj = j + DY[newDir];
      if (ti >= 0 && ti < m && tj >= 0 && tj < n && grid[ti][tj] == nextVal) {
        int tempLen = 1 + exploreDP(grid, ti, tj, newDir, TURNED);
        if (tempLen > len)
          len = tempLen;
      }
    }

    return dp[i][j][dir][turnState] = len;
  }

public:
  int lenOfVDiagonal(std::vector<std::vector<int>> &grid) {
    m = grid.size();
    n = grid[0].size();

    dp.assign(
        m, std::vector<std::vector<std::vector<int>>>(
               n, std::vector<std::vector<int>>(4, std::vector<int>(2, -1))));

    int maxLen = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1)
          for (int d = 0; d < 4; ++d) {
            int tempLen = exploreDP(grid, i, j, d, NO_TURN);
            if (tempLen > maxLen)
              maxLen = tempLen;
          }

    return maxLen;
  }
};
