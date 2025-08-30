#include <algorithm>
#include <vector>

class Solution {
  int di[4] = {1, -1, 1, -1}, dj[4] = {1, -1, -1, 1}, n, m, c[4] = {2, 3, 1, 0};
  std::vector<std::vector<int>> *g;

  int explore(int i, int j, int d, int t) {
    int ni = i + di[d], nj = j + dj[d], tr = ((*g)[i][j] == 2 ? 0 : 2);

    if (ni < 0 || nj < 0 || ni >= n || nj >= m || (*g)[ni][nj] != tr)
      return 0;

    int l = explore(ni, nj, d, t);

    if (!t)
      l = std::max(explore(ni, nj, c[d], 1), l);

    return l + 1;
  }

public:
  int lenOfVDiagonal(std::vector<std::vector<int>> &grid) {
    g = &grid;
    n = grid.size(), m = grid[0].size();
    int res = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          int l[4] = {n - i, i + 1, j + 1, m - j};

          for (int d = 0; d < 4; ++d)
            if (l[d] > res)
              res = std::max(res, explore(i, j, d, 0) + 1);
        }
      }
    }

    return res;
  }
};

/*
//dp version
#include <algorithm>
#include <vector>

class Solution {
  int di[4] = {1, -1, 1, -1}, dj[4] = {1, -1, -1, 1}, n, m, c[4] = {2, 3, 1, 0};
  std::vector<std::vector<int>> *g;
  int *dp;

  int explore(int i, int j, int d, int t) {
    int ni = i + di[d], nj = j + dj[d], tr = ((*g)[i][j] == 2 ? 0 : 2);

    if (ni < 0 || nj < 0 || ni >= n || nj >= m || (*g)[ni][nj] != tr)
      return 0;

    int &l = dp[((i * m + j) * 4 + d) * 2 + t];

    if (l == -1) {
      l = explore(ni, nj, d, t);

      if (!t)
        l = std::max(explore(ni, nj, c[d], 1), l);

      ++l;
    }

    return l;
  }

public:
  int lenOfVDiagonal(std::vector<std::vector<int>> &grid) {
    g = &grid;
    n = grid.size(), m = grid[0].size();
    int res = 0;

    dp = new int[m * n * 4 * 2];
    std::fill(dp, dp + n * m * 4 * 2, -1);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          int l[4] = {n - i, i + 1, j + 1, m - j};

          for (int d = 0; d < 4; ++d)
            if (l[d] > res)
              res = std::max(res, explore(i, j, d, 0) + 1);
        }
      }
    }

    delete[] dp;

    return res;
  }
};

 */
