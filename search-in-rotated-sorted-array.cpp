#include <cstdint>
#include <vector>

class Solution {
public:
  int search(std::vector<int> &nums, int target) {
    std::size_t l = 0, r = nums.size() - 1, m;

    while (l <= r && r != SIZE_MAX) {
      m = l + (r - l) / 2;

      if (nums[m] == target)
        return m;

      if (nums[l] <= nums[m]) {
        if (nums[l] <= target && target < nums[m]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      } else {
        if (nums[m] < target && target <= nums[r]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }

    return -1;
  }
};
