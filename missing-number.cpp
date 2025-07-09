#include <vector>

class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    int sum = nums.size() * (nums.size() + 1) / 2, currentSum = 0;

    for (int num : nums)
      currentSum += num;

    return sum - currentSum;
  }
};
