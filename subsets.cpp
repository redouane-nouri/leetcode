#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
    std::vector<std::vector<int>> res;
    std::vector<int> subset;
    dfs(res, subset, nums, nums.size());
    return res;
  }

private:
  void dfs(std::vector<std::vector<int>> &res, std::vector<int> &subset,
           std::vector<int> &nums, int n) {
    res.push_back(subset);

    for (int i = n - 1; i >= 0; --i) {
      subset.push_back(nums[i]);
      dfs(res, subset, nums, i);
      subset.pop_back();
    }
  }
};
