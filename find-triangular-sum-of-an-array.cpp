#include <vector>

class Solution {
public:
  int triangularSum(std::vector<int> &nums) {
    int n = nums.size() - 1;

    while (n > 0) {
      for (int i = 0; i < n; ++i)
        nums[i] = (nums[i] + nums[i + 1]) % 10;

      --n;
    }

    return nums[0];
  }
};
