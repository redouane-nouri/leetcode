#include <vector>

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    int r[9] = {0}, c[9] = {0}, b[9] = {0};

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          int m = 1 << (board[i][j] - '0'), bi = i / 3 * 3 + j / 3;

          if ((r[i] & m) || (c[j] & m) || (b[bi] & m))
            return false;

          r[i] |= m;
          c[j] |= m;
          b[bi] |= m;
        }
      }
    }

    return true;
  }
};
