#include <vector>

class Solution {
public:
  int totalNQueens(int n) {
    std::vector<bool> mainDiagonal(n * 2 - 1, false),
        secondaryDiagonal(n * 2 - 1, false), columns(n, false);
    int res = 0;

    solve(n, 0, mainDiagonal, secondaryDiagonal, columns, res);

    return res;
  }

private:
  void solve(int n, int row, std::vector<bool> &mainDiagonal,
             std::vector<bool> &secondaryDiagonal, std::vector<bool> &columns,
             int &res) {
    if (n == row) {
      ++res;
      return;
    }

    for (int col = 0; col < n; ++col) {
      if (columns[col] || mainDiagonal[row - col + n - 1] ||
          secondaryDiagonal[row + col])
        continue;

      columns[col] = mainDiagonal[row - col + n - 1] =
          secondaryDiagonal[row + col] = true;

      solve(n, row + 1, mainDiagonal, secondaryDiagonal, columns, res);

      columns[col] = mainDiagonal[row - col + n - 1] =
          secondaryDiagonal[row + col] = false;
    }
  }
};
