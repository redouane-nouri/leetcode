#include <utility>
#include <vector>

class Solution {
public:
  void sortColors(std::vector<int> &nums) {
    int redI = 0, whiteI = 0, sz = nums.size();

    for (int i = 0; i < sz; ++i) {
      if (nums[i] == 0) {
        std::swap(nums[redI++], nums[i]);

        if (nums[i] == 1)
          std::swap(nums[whiteI], nums[i]);

        ++whiteI;
      } else if (nums[i] == 1) {
        std::swap(nums[whiteI++], nums[i]);
      }
    }
  }
};
