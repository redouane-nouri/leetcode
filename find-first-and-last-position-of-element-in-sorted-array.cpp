#include <cstdint>
#include <vector>

class Solution {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    int l = binarySearch(nums, target, false), r = -1;

    if (l != -1)
      r = binarySearch(nums, target, true);

    return {l, r};
  }

private:
  int binarySearch(std::vector<int> &nums, int target, bool toRight) {
    int32_t l = 0, r = nums.size() - 1, m;
    int i = -1;

    while (l <= r) {
      m = l + (r - l) / 2;

      if (nums[m] == target) {
        i = m;

        if (toRight)
          l = m + 1;
        else
          r = m - 1;

        continue;
      }

      if (nums[m] < target)
        l = m + 1;
      else
        r = m - 1;
    }

    return i;
  }
};
