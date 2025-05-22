#include <vector>

class Solution {
public:
  int singleNumber(std::vector<int> &nums) {
    int r = 0;
    for (int n : nums) {
      r ^= n;
    }

    return r;
  }
};
