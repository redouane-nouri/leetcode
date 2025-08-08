#include <vector>

class Solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    const int n = nums.size();

    if (n <= 2)
      return n;

    int j = 2;

    for (int i = 2; i < n; ++i) {
      if (nums[i] != nums[j - 2]) {
        nums[j] = nums[i];
        ++j;
      }
    }

    return j;
  }
};
