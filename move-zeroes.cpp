#include <vector>

class Solution {
public:
  void moveZeroes(std::vector<int> &nums) {
    int sz = nums.size(), zi = 0;

    for (int i = 0; i < sz; ++i)
      if (nums[i] != 0)
        nums[zi++] = nums[i];

    for (int i = zi; i < sz; ++i)
      nums[i] = 0;
  }
};
