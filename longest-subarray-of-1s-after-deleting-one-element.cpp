#include <vector>

class Solution {
public:
  int longestSubarray(std::vector<int> &nums) {
    int n = nums.size(), res = 0, l = 0;
    bool hasZ = false;

    for (int r = 0; r < n; ++r) {
      if (nums[r] == 0) {
        if (hasZ) {
          while (nums[l++] == 1) {
          }
        } else {
          hasZ = true;
        }
      }

      if (r - l > res)
        res = r - l;
    }

    return res;
  }
};
