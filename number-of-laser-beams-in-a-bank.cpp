#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
  int numberOfBeams(std::vector<std::string> &bank) {
    int prev = 0, res = 0;

    for (std::string &b : bank) {
      int ones = std::count(b.begin(), b.end(), '1');

      if (ones) {
        res += prev * ones;
        prev = ones;
      }
    }

    return res;
  }
};
