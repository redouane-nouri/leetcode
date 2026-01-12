#include <algorithm>
#include <cstdlib>
#include <vector>

class Solution {
public:
  int minTimeToVisitAllPoints(std::vector<std::vector<int>> &points) {
    int ans = 0;
    std::vector<int> &from = points[0];

    for (auto &to : points) {
      ans += std::max(std::abs(from[0] - to[0]), std::abs(from[1] - to[1]));
      from = to;
    }

    return ans;
  }
};
