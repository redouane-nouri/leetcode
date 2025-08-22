#include <vector>

class Solution {
public:
  int numSubmat(std::vector<std::vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size(), res = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (mat[i][j]) {
          if (j)
            mat[i][j] += mat[i][j - 1];

          for (int w = mat[i][j], k = i; k >= 0 && mat[k][j]; --k) {
            if (mat[k][j] < w)
              w = mat[k][j];

            res += w;
          }
        }
      }
    }

    return res;
  }
};
