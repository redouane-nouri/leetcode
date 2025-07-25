#include <vector>

class Solution {
public:
  void setZeroes(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool setRow = false, setColumn = false;

    for (int j = 0; j < n; ++j) {
      if (matrix[0][j] == 0) {
        setRow = true;
        break;
      }
    }

    for (int i = 0; i < m; ++i) {
      if (matrix[i][0] == 0) {
        setColumn = true;
        break;
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;
      }
    }

    if (setRow) {
      for (int j = 0; j < n; ++j) {
        matrix[0][j] = 0;
      }
    }

    if (setColumn) {
      for (int i = 0; i < m; ++i) {
        matrix[i][0] = 0;
      }
    }
  }
};
