#include <algorithm>
#include <vector>

class Solution {
public:
  int maxArea(std::vector<int> &height) {
    std::size_t l = 0, r = height.size() - 1;
    int res = 0;

    while (l < r) {
      res = std::max(
          res, static_cast<int>(std::min(height[l], height[r]) * (r - l)));
      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }

    return res;
  }
};
