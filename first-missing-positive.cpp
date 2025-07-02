#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
  int firstMissingPositive(std::vector<int> &nums) {
    int numsSize = nums.size();

    for (int i = 0; i < numsSize; ++i) {
      while (nums[i] > 0 && nums[i] <= numsSize &&
             nums[nums[i] - 1] != nums[i]) {
        std::swap(nums[nums[i] - 1], nums[i]);
      }
    }

    for (int j = 0; j < numsSize; ++j) {
      if (nums[j] != j + 1)
        return j + 1;
    }

    return numsSize + 1;
  }
};
