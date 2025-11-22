#include <vector>

class Solution {
public:
  int minimumOperations(std::vector<int> &nums) {
    int res = 0;

    for (int &num : nums) {
      if (num % 3 != 0) {
        ++res;
      }
    }

    return res;
  }
};
