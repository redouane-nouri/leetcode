#include <vector>

class Solution {
public:
  int minNumberOperations(std::vector<int> &target) {
    int res = 0, prev = 0;

    for (int &t : target) {
      if (t < prev) {
        res += t - prev;
      }

      prev = t;
    }

    return res;
  }
};
