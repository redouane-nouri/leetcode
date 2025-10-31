#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<int> getSneakyNumbers(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> res;
    res.reserve(2);

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] == nums[i - 1]) {
        res.push_back(nums[i]);
      }
    }

    return res;
  }
};
