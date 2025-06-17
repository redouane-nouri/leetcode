#include <unordered_set>
#include <vector>

class Solution {
public:
  bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
    const int s = nums.size();

    if (k == 0 || s <= 1) {
      return false;
    }

    std::unordered_set<int> w;

    for (int i = 0; i < s; ++i) {
      if (w.count(nums[i]))
        return true;

      w.insert(nums[i]);

      if (i >= k)
        w.erase(nums[i - k]);
    }

    return false;
  }
};
