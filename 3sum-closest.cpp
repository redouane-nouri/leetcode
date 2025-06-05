#include <algorithm>
#include <vector>

class Solution {
public:
  int threeSumClosest(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());

    int sum = nums[0] + nums[1] + nums[2], tmpSum;
    const std::size_t sz = nums.size();
    std::size_t l, r;

    for (std::size_t i = 0; i < sz - 2; ++i) {
      l = i + 1;
      r = sz - 1;

      while (l < r) {
        tmpSum = nums[i] + nums[l] + nums[r];

        if (tmpSum == target) {
          return target;
        }

        if (std::abs(sum - target) > std::abs(tmpSum - target)) {
          sum = tmpSum;
        }

        if (tmpSum < target) {
          ++l;
        } else {
          --r;
        }
      }
    }

    return sum;
  }
};
