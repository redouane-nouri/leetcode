#include <algorithm>
#include <climits>
#include <numeric>
#include <vector>

class Solution {
public:
  int minOperations(std::vector<int> &nums) {
    const int n = nums.size(), ones = std::count(nums.begin(), nums.end(), 1);

    if (ones != 0) {
      return n - ones;
    }

    int minOps = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int g = nums[i];

      for (int j = i + 1; j < n; ++j) {
        g = std::gcd(g, nums[j]);

        if (g == 1) {
          minOps = std::min(minOps, j - i);
          break;
        }
      }

      if (minOps == 1) {
        break;
      }
    }

    if (minOps == INT_MAX) {
      return -1;
    }

    return minOps + n - 1;
  }
};
