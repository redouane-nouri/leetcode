#include <algorithm>
#include <vector>

class Solution {
public:
  int maxIncreasingSubarrays(std::vector<int> &nums) {
    int l = 1, r = 1, res = 1;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        ++r;
      } else {
        res = std::max({res, std::min(l, r), l / 2, r / 2});
        l = r;
        r = 1;
      }
    }

    res = std::max({res, std::min(l, r), l / 2, r / 2});
    return res;
  }
};
