#include <algorithm>
#include <vector>

class Solution {
public:
  int findFinalValue(std::vector<int> &nums, int original) {
    std::sort(nums.begin(), nums.end());
    const int maxIndex = nums.size() - 1;

    if (original > nums[maxIndex]) {
      return original;
    }

    for (int &num : nums) {
      if (num == original) {
        original *= 2;

        if (original > nums[maxIndex]) {
          return original;
        }
      }
    }

    return original;
  }
};
