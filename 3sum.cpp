#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums) {
    const std::size_t sz = nums.size();
    std::size_t l, r;
    std::vector<std::vector<int>> res;
    int s;

    std::sort(nums.begin(), nums.end());

    for (std::size_t i = 0; i < sz - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      if (nums[i] > 0) {
        break;
      }

      l = i + 1;
      r = sz - 1;

      while (l < r) {
        s = nums[i] + nums[l] + nums[r];

        if (s == 0) {
          res.push_back({nums[i], nums[l], nums[r]});
          while (l < r && nums[l] == nums[l + 1]) {
            ++l;
          }

          while (l < r && nums[r] == nums[r - 1]) {
            --r;
          }

          ++l;
          --r;
        } else if (s < 0) {
          ++l;
        } else {
          --r;
        }
      }
    }

    return res;
  }
};
