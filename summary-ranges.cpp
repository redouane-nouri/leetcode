#include <string>
#include <vector>

class Solution {
public:
  std::vector<std::string> summaryRanges(std::vector<int> &nums) {
    int numsSize = nums.size();
    std::vector<std::string> res;

    for (int i = 0; i < numsSize; ++i) {
      int a = nums[i];

      while (i + 1 < numsSize && nums[i + 1] == nums[i] + 1)
        ++i;

      if (a == nums[i])
        res.push_back(std::to_string(a));
      else
        res.push_back(std::to_string(a) + "->" + std::to_string(nums[i]));
    }

    return res;
  }
};
