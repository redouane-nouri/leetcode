#include <algorithm>
#include <vector>

class Solution {
public:
  int triangleNumber(std::vector<int> &nums) {
    int n = nums.size();

    if (n < 3)
      return 0;

    std::sort(nums.begin(), nums.end());

    int res = 0;
    for (int i = n - 1; i >= 2; --i) {
      int j = 0, k = i - 1;

      while (j < k)
        if (nums[j] + nums[k] > nums[i])
          res += k-- - j;
        else
          ++j;
    }

    return res;
  }
};
