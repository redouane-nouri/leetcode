#include <algorithm>
#include <vector>

class Solution {
  void build(std::vector<std::vector<int>> &res, std::vector<int> &nums,
             std::vector<int> &curr, int start, int end) {
    res.push_back(curr);

    for (int i = start; i < end; ++i) {
      if (i == start || nums[i] != nums[i - 1]) {
        curr.push_back(nums[i]);
        build(res, nums, curr, i + 1, end);
        curr.pop_back();
      }
    }
  }

public:
  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> curr = {};

    std::sort(nums.begin(), nums.end());
    build(res, nums, curr, 0, nums.size());

    return res;
  }
};
