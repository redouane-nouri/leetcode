#include <vector>

class Solution {
public:
  int jump(std::vector<int> &nums) {
    const int size = nums.size();
    int max = 0, jumps = 0, windowEnd = 0;

    for (int i = 0; i < size - 1; ++i) {
      if (max < nums[i] + i)
        max = nums[i] + i;

      if (i == windowEnd) {
        ++jumps;
        windowEnd = max;
      }
    }

    return jumps;
  }
};
