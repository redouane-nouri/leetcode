#include <algorithm>
#include <vector>

class Solution {
public:
  int largestPerimeter(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size() - 1;

    for (int i = n; i >= 2; --i) {
      int &a = nums[i - 2], &b = nums[i - 1], &c = nums[i];

      if (a + b > c)
        return a + b + c;
    }
    return 0;
  }
};
