#include <vector>

class Solution {
  int r[9] = {0}, c[9] = {0}, b[9] = {0};
  std::vector<int> e;
  std::vector<std::vector<char>> *bo;

  bool solve(int ix) {
    if (ix == e.size())
      return true;

    int i = e[ix], j = e[ix + 1], bi = (i / 3) * 3 + (j / 3);

    for (int d = 0; d < 9; ++d) {
      if (!((r[i] | c[j] | b[bi]) & (1 << d))) {
        (*bo)[i][j] = d + '1';
        r[i] |= 1 << d;
        c[j] |= 1 << d;
        b[bi] |= 1 << d;

        if (solve(ix + 2))
          return true;

        (*bo)[i][j] = '.';
        r[i] ^= 1 << d;
        c[j] ^= 1 << d;
        b[bi] ^= 1 << d;
      }
    }

    return false;
  }

public:
  void solveSudoku(std::vector<std::vector<char>> &board) {
    bo = &board;

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          int d = board[i][j] - '1';
          r[i] |= 1 << d;
          c[j] |= 1 << d;
          b[(i / 3) * 3 + (j / 3)] |= 1 << d;
        } else {
          e.push_back(i);
          e.push_back(j);
        }
      }
    }

    solve(0);
  }
};
