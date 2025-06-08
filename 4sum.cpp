#include <algorithm>
#include <vector>

#define SKIP_DUPLICATES_FORWARD                                                \
  while (l < r && nums[l] == nums[l + 1]) {                                    \
    ++l;                                                                       \
  }

#define SKIP_DUPLICATES_BACKWARD                                               \
  while (l < r && nums[r] == nums[r - 1]) {                                    \
    --r;                                                                       \
  }

class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    const std::size_t sz = nums.size();

    if (sz < 4) {
      return {};
    }

    std::sort(nums.begin(), nums.end());
    std::size_t l, r;
    std::vector<std::vector<int>> res;
    long long sum;

    for (std::size_t i = 0; i < sz - 3; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      for (std::size_t j = i + 1; j < sz - 2; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }

        l = j + 1;
        r = sz - 1;

        while (l < r) {
          sum = static_cast<long long>(nums[i]) + nums[j] + nums[l] + nums[r];

          if (sum == target) {
            res.push_back({nums[i], nums[j], nums[l], nums[r]});

            SKIP_DUPLICATES_FORWARD
            SKIP_DUPLICATES_BACKWARD

            ++l;
            --r;
          } else if (sum > target) {
            SKIP_DUPLICATES_BACKWARD
            --r;
          } else {
            SKIP_DUPLICATES_FORWARD
            ++l;
          }
        }
      }
    }

    return res;
  }
};
