#include <algorithm>
#include <vector>

class Solution {
public:
  int trap(std::vector<int> &height) {
    int res = 0, l = 0, r = height.size() - 1, lmx = 0, rmx = 0;

    while (l < r) {
      if (height[l] <= height[r]) {
        if (height[l] >= lmx) {
          lmx = height[l];
        } else {
          res += lmx - height[l];
        }
        ++l;
      } else {
        if (height[r] >= rmx) {
          rmx = height[r];
        } else {
          res += rmx - height[r];
        }
        --r;
      }
    }

    return res;
  }
};
