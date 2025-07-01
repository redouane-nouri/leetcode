#include <vector>

class Solution {
public:
  void solveSudoku(std::vector<std::vector<char>> &board) { answer(board); }

private:
  bool answer(std::vector<std::vector<char>> &b) {
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (b[i][j] == '.') {
          for (char c = '1'; c <= '9'; ++c) {
            if (satisfied(b, i, j, c)) {
              b[i][j] = c;
              if (answer(b))
                return true;

              b[i][j] = '.';
            }
          }

          return false;
        }
      }
    }

    return true;
  }
  bool satisfied(std::vector<std::vector<char>> &b, int i, int j, char c) {
    for (int k = 0; k < 9; ++k)
      if (b[i][k] == c || b[k][j] == c ||
          b[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3] == c)
        return false;

    return true;
  }
};
