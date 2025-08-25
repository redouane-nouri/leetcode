#include <vector>

class Solution {
public:
  std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    bool up = true;
    std::vector<int> res;

    res.reserve(m * n);

    for (int k = 0; k < m + n - 1; ++k) {
      int i, j;

      if (up) {
        i = k < m ? k : m - 1;
        j = k - i;

        while (i >= 0 && j < n)
          res.push_back(mat[i--][j++]);
      } else {
        j = k < n ? k : n - 1;
        i = k - j;

        while (j >= 0 && i < m)
          res.push_back(mat[i++][j--]);
      }

      up = !up;
    }

    return res;
  }
};
