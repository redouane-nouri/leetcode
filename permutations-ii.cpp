#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    std::vector<bool> used(nums.size(), false);
    std::vector<int> current;
    std::sort(nums.begin(), nums.end());
    backtrack(nums, result, current, used);
    return result;
  }

private:
  void backtrack(std::vector<int> &nums, std::vector<std::vector<int>> &result,
                 std::vector<int> &current, std::vector<bool> &used) {
    if (current.size() == nums.size()) {
      result.push_back(current);
      return;
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (used[i])
        continue;

      if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
        continue;

      used[i] = true;
      current.push_back(nums[i]);
      backtrack(nums, result, current, used);
      current.pop_back();
      used[i] = false;
    }
  }
};
