#include <vector>

class Solution {
public:
  bool kLengthApart(std::vector<int> &nums, int k) {
    int d = k;
    for (int &num : nums) {
      if (num == 0) {
        ++d;
      } else {
        if (d < k) {
          return false;
        }
        d = 0;
      }
    }
    return true;
  }
};
