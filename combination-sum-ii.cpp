#include <algorithm>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates,
                                                int target) {
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> result;
    std::vector<int> currentCombination;
    int size = candidates.size();

    backtrack(0, currentCombination, candidates, result, target, size);

    return result;
  }

private:
  void backtrack(int startIndex, std::vector<int> &currentCombination,
                 std::vector<int> &candidates,
                 std::vector<std::vector<int>> &result, int target, int size) {
    if (target == 0) {
      result.push_back(currentCombination);
      return;
    }

    for (int i = startIndex; i < size; ++i) {
      if (candidates[i] > target)
        return;

      if (i > startIndex && candidates[i - 1] == candidates[i])
        continue;

      currentCombination.push_back(candidates[i]);
      backtrack(i + 1, currentCombination, candidates, result,
                target - candidates[i], size);
      currentCombination.pop_back();
    }
  }
};
