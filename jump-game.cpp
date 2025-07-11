#include <vector>

class Solution {
public:
  bool canJump(std::vector<int> &nums) {
    int sz = nums.size(), mxi = 0;

    for (int i = 0; i <= mxi; ++i) {
      if (mxi < i + nums[i])
        mxi = i + nums[i];

      if (mxi >= sz - 1)
        return true;
    }

    return false;
  }
};
