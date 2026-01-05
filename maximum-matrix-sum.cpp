#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>

class Solution {
public:
  long long maxMatrixSum(std::vector<std::vector<int>> &matrix) {
    long long sum = 0;
    int minAbs = INT_MAX, negativesCount = 0;

    for (const auto &r : matrix) {
      for (const int &v : r) {
        if (v < 0)
          ++negativesCount;

        minAbs = std::min(minAbs, std::abs(v));
        sum += std::abs(v);
      }
    }

    if (negativesCount % 2)
      sum -= 2 * minAbs;

    return sum;
  }
};
