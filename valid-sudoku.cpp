#include <unordered_set>
#include <vector>

#define CHECK_AND_INSERT                                                       \
  if (c == '.')                                                                \
    continue;                                                                  \
  if (nums.count(c))                                                           \
    return false;                                                              \
  nums.insert(c);

class Solution {
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board) {
    std::unordered_set<char> nums;
    char c;
    int r, co;

    for (int i = 0; i < 9; ++i) {
      nums.clear();

      for (int j = 0; j < 9; ++j) {
        c = board[i][j];

        CHECK_AND_INSERT
      }

      nums.clear();

      for (int j = 0; j < 9; ++j) {
        c = board[j][i];

        CHECK_AND_INSERT
      }

      nums.clear();

      r = (i / 3) * 3;
      co = (i % 3) * 3;

      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          c = board[r + j][co + k];

          CHECK_AND_INSERT
        }
      }
    }

    return true;
  }
};
