#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
  void nextPermutation(std::vector<int> &nums) {
    const std::size_t sz = nums.size();
    std::size_t i = sz - 1, j = i;

    while (i > 0 && nums[i] <= nums[i - 1]) {
      --i;
    }

    if (i != 0) {
      while (j >= i && nums[j] <= nums[i - 1]) {
        --j;
      }

      std::swap(nums[i - 1], nums[j]);
      std::reverse(nums.begin() + i, nums.end());
    } else {
      std::reverse(nums.begin(), nums.end());
    }
  }
};
