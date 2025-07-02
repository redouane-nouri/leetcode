#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> res;
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<bool> cols(n, false), mainDiagonal(n * 2 - 1, false),
        antiDiagonal(n * 2 - 1, false);

    solve(res, board, cols, mainDiagonal, antiDiagonal, n, 0);

    return res;
  }

private:
  void solve(std::vector<std::vector<std::string>> &res,
             std::vector<std::string> &board, std::vector<bool> &cols,
             std::vector<bool> &mainDiagonal, std::vector<bool> &antiDiagonal,
             int n, int row) {
    if (row == n) {
      res.push_back(board);
      return;
    }

    for (int col = 0; col < n; ++col) {
      if (cols[col] || mainDiagonal[row - col + n - 1] ||
          antiDiagonal[row + col])
        continue;

      cols[col] = mainDiagonal[row - col + n - 1] = antiDiagonal[row + col] =
          true;
      board[row][col] = 'Q';

      solve(res, board, cols, mainDiagonal, antiDiagonal, n, row + 1);

      board[row][col] = '.';
      cols[col] = mainDiagonal[row - col + n - 1] = antiDiagonal[row + col] =
          false;
    }
  }
};
