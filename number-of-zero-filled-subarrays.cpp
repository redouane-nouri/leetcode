#include <vector>

class Solution {
public:
  long long zeroFilledSubarray(std::vector<int> &nums) {
    long long res = 0;
    int n = nums.size(), m = 0;

    for (int i = 0; i < n; ++i)
      if (nums[i] == 0)
        res += ++m;
      else
        m = 0;

    return res;
  }
};
