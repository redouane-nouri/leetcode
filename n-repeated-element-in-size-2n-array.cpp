#include <bitset>
#include <vector>

class Solution {
public:
  int repeatedNTimes(std::vector<int> &nums) {
    std::bitset<10001> seen;

    for (const int &num : nums) {
      if (seen.test(num))
        return num;

      seen.set(num);
    }

    return -1;
  }
};
