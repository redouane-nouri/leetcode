#include <vector>

class Solution {
public:
  std::vector<bool> prefixesDivBy5(std::vector<int> &nums) {
    const int n = nums.size();
    std::vector<bool> res(n);

    int remainder = 0;
    for (int i = 0; i < n; ++i) {
      remainder = ((remainder << 1) + nums[i]) % 5;
      res[i] = remainder == 0;
    }

    return res;
  }
};
