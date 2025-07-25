#include <vector>

class Solution {
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int l = 0, m = matrix.size(), n = matrix[0].size(), r = m * n - 1;

    while (l <= r) {
      int mi = l + (r - l) / 2, mid = matrix[mi / n][mi % n];

      if (target == mid)
        return true;
      else if (target < mid)
        r = mi - 1;
      else
        l = mi + 1;
    }

    return false;
  }
};
