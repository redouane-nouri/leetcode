#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
  int maxDistinctElements(std::vector<int> &nums, int k) {
    std::sort(nums.begin(), nums.end());
    int res = 0, last = INT_MIN;

    for (int &num : nums) {
      int mn = std::max(num - k, last + 1);

      if (mn <= num + k) {
        ++res;
        last = mn;
      }
    }

    return res;
  }
};
