
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> permute(std::vector<int> &nums) {
    std::vector<std::vector<int>> result;
    backtrack(result, nums, 0, nums.size());
    return result;
  }

private:
  void backtrack(std::vector<std::vector<int>> &result, std::vector<int> &nums,
                 int start, int size) {
    if (start < size) {
      for (int i = start; i < size; ++i) {
        int tmp = nums[start];
        nums[start] = nums[i];
        nums[i] = tmp;
        backtrack(result, nums, start + 1, size);
        nums[i] = nums[start];
        nums[start] = tmp;
      }
    } else {
      result.push_back(nums);
    }
  }
};
