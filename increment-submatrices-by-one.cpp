#include <vector>

class Solution {
public:
  std::vector<std::vector<int>>
  rangeAddQueries(int n, std::vector<std::vector<int>> &queries) {
    std::vector<std::vector<int>> preSum(n, std::vector<int>(n + 1, 0)),
        res(n, std::vector<int>(n));

    for (auto &q : queries) {
      int row1 = q[0], col1 = q[1], row2 = q[2], col2 = q[3];
      for (int row = row1; row <= row2; ++row) {
        preSum[row][col1] += 1;
        preSum[row][col2 + 1] -= 1;
      }
    }

    for (int i = 0; i < n; ++i) {
      int inc = 0;
      for (int j = 0; j < n; ++j) {
        inc += preSum[i][j];
        res[i][j] = inc;
      }
    }

    return res;
  }
};
