#include <vector>

class Solution {
public:
  bool hasIncreasingSubarrays(std::vector<int> &nums, int k) {
    if (k << 1 > nums.size()) {
      return false;
    }

    int l = 1, r = 1;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        ++r;
      } else {
        l = r;
        r = 1;
      }

      if ((l == k << 1 || r == k << 1) || (l >= k && r >= k)) {
        return true;
      }
    }
    return false;
  }
};
