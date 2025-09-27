#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
public:
  double largestTriangleArea(std::vector<std::vector<int>> &points) {
    int n = points.size();
    double res = 0.0;

    for (int i = 0; i < n - 2; ++i)
      for (int j = i + 1; j < n - 1; ++j)
        for (int k = j + 1; k < n; ++k)
          res =
              std::max(res, 0.5 * std::abs((points[j][0] - points[i][0]) *
                                               (points[k][1] - points[i][1]) -
                                           (points[j][1] - points[i][1]) *
                                               (points[k][0] - points[i][0])));

    return res;
  }
};
