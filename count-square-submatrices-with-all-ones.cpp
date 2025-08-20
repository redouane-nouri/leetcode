#include <algorithm>
#include <vector>

class Solution {
public:
  int countSquares(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size(), res = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (matrix[i][j] && i > 0 && j > 0) {
          matrix[i][j] += std::min(std::min(matrix[i - 1][j], matrix[i][j - 1]),
                                   matrix[i - 1][j - 1]);
        }

        res += matrix[i][j];
      }
    }

    return res;
  }
};
