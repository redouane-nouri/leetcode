#include <algorithm>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int maxSum = nums[0], sum = nums[0], numsSize = nums.size();

    for (int i = 1; i < numsSize; ++i) {
      sum = std::max(nums[i] + sum, nums[i]);

      if (sum > maxSum)
        maxSum = sum;
    }

    return maxSum;
  }
};
