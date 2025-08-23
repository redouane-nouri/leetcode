#include <vector>

class Solution {
  std::vector<std::vector<int>> *grid;
  constexpr static int INF = 2'147'483'647;

  int getMinArea(int is, int ie, int js, int je) {
    int t = -1, b = -1, l = je, r = -1;

    for (int i = is; i <= ie; ++i) {
      for (int j = js; j <= je; ++j) {
        if ((*grid)[i][j]) {
          if (t == -1)
            t = i;

          b = i;

          if (l > j)
            l = j;

          if (r < j)
            r = j;
        }
      }
    }

    return b == -1 ? 0 : (b - t + 1) * (r - l + 1);
  }

public:
  int minimumSum(std::vector<std::vector<int>> &grid) {
    this->grid = &grid;
    int m = grid.size(), n = grid[0].size(), t = -1, b, l = n, r = -1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j]) {
          if (t == -1)
            t = i;

          b = i;

          if (l > j)
            l = j;

          if (r < j)
            r = j;
        }
      }
    }

    int res = INF;

    // horizontal
    for (int i = t; i < b - 1; ++i) {
      for (int j = i + 1; j < b; ++j) {
        int a1 = getMinArea(t, i, l, r);
        if (a1) {
          int a2 = getMinArea(i + 1, j, l, r);
          if (a2) {
            int a3 = getMinArea(j + 1, b, l, r), a = a1 + a2 + a3;
            if (res > a)
              res = a;
          }
        }
      }
    }

    // vertical
    for (int i = l; i < r - 1; ++i) {
      for (int j = i + 1; j < r; ++j) {
        int a1 = getMinArea(t, b, l, i);
        if (a1) {
          int a2 = getMinArea(t, b, i + 1, j);
          if (a2) {
            int a3 = getMinArea(t, b, j + 1, r), a = a1 + a2 + a3;
            if (res > a)
              res = a;
          }
        }
      }
    }

    // top horizontal and bottom vertically
    for (int i = t; i < b; ++i) {
      int a1 = getMinArea(t, i, l, r);
      if (a1) {
        for (int j = l; j < r; j++) {
          int a2 = getMinArea(i + 1, b, l, j);
          if (a2) {
            int a3 = getMinArea(i + 1, b, j + 1, r), a = a1 + a2 + a3;
            if (res > a)
              res = a;
          }
        }
      }
    }

    // bottom horizontal and top vertically
    for (int i = t; i < b; ++i) {
      int a1 = getMinArea(i + 1, b, l, r);
      if (a1) {
        for (int j = l; j < r; j++) {
          int a2 = getMinArea(t, i, l, j);
          if (a2) {
            int a3 = getMinArea(t, i, j + 1, r), a = a1 + a2 + a3;
            if (res > a)
              res = a;
          }
        }
      }
    }

    // left vertical and right horizontally
    for (int j = l; j < r; ++j) {
      int a1 = getMinArea(t, b, l, j);
      if (a1) {
        for (int i = t; i < b; i++) {
          int a2 = getMinArea(t, i, j + 1, r);
          if (a2) {
            int a3 = getMinArea(i + 1, b, j + 1, r), a = a1 + a2 + a3;
            if (res > a)
              res = a;
          }
        }
      }
    }

    // right vertical and left horizontally
    for (int j = l; j < r; ++j) {
      int a1 = getMinArea(t, b, j + 1, r);
      if (a1) {
        for (int i = t; i < b; i++) {
          int a2 = getMinArea(t, i, l, j);
          if (a2) {
            int a3 = getMinArea(i + 1, b, l, j), a = a1 + a2 + a3;
            if (res > a)
              res = a;
          }
        }
      }
    }

    return res == INF ? 0 : res;
  }
};
