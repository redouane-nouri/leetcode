#include <vector>

class Solution {
  std::vector<std::vector<char>> *b;
  int m, n;

  void discover(int i, int j) {
    if ((*b)[i][j] != 'O')
      return;

    (*b)[i][j] = '#';

    if (j < n - 1)
      discover(i, j + 1);

    if (i < m - 1)
      discover(i + 1, j);

    if (j > 0)
      discover(i, j - 1);

    if (i > 0)
      discover(i - 1, j);
  }

public:
  void solve(std::vector<std::vector<char>> &board) {
    m = board.size();
    n = board[0].size();
    b = &board;

    for (int j = 0; j < n; ++j) {
      discover(0, j);
      discover(m - 1, j);
    }

    for (int i = 0; i < m; ++i) {
      discover(i, 0);
      discover(i, n - 1);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        board[i][j] = board[i][j] == '#' ? 'O' : 'X';
  }
};
